/*********************************************************************
Quinn Schwab
16/08/2010

SFML Tiled Map Loader

The zlib license has been used to make this software fully compatible
with SFML. See http://www.sfml-dev.org/license.php

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.
*********************************************************************/

#include "level.hpp"

namespace Game { namespace Entidades { namespace Mapas {

int Object::GetPropertyInt(std::string name)
{
    int i;
    i = atoi(properties[name].c_str());

    return i;
}

float Object::GetPropertyFloat(std::string name)
{
    float f;
    f = strtod(properties[name].c_str(), NULL);

    return f;
}

std::string Object::GetPropertyString(std::string name)
{
    return properties[name];
}

// Constructor & Destructor
Mapa::Mapa( GerenciadorGrafico* g_grafico, const string& a_tilemap, const string& a_tileset, Texture* texture):
Entidade(texture, g_grafico),
width(0),
height(0),
tileWidth(0),
tileHeight(0),
spacing(0),
margin(0),
firstTileID(-1),
background(),
drawingBounds(),
tilesetImage(),
tilesetTexture(),
solidObjects(),
objects(),
layers(),
a_tilemap(a_tilemap),
a_tileset(a_tileset)
{
    this->initBackground();
}

Mapa::~Mapa()
{

}

// Init Methods
void Mapa::initBackground(){
    this->background.setSize(Vector2f(this->g_grafico->getRenderWindow()->getSize()));
    if (this->texture != nullptr)
        this->background.setTexture(this->texture);
}

// Methods
void Mapa::move(const sf::Vector2f &direction, const float &dt){
    if (this->g_grafico->moveView(direction.x, direction.y))
        this->background.move(direction.x, direction.y);
}

void Mapa::update(const float &dt){
    //View view = *this->g_grafico->getView();
    //view.move(1, 0);
    //this->g_grafico->getRenderWindow()->setView(view);
    sf::FloatRect rect = this->g_grafico->getRenderWindow()->getView().getViewport();
    auto size = this->g_grafico->getRenderWindow()->getSize();
    rect.left = this->g_grafico->getView()->getCenter().x - size.x/2;
    rect.top = this->g_grafico->getView()->getCenter().y - size.y/2;
    rect.width = size.x;
    rect.height = size.y;
    this->SetDrawingBounds(rect);
}

void Mapa::render(RenderTarget *target){
    if (target == nullptr) // Verifica target
        target = this->g_grafico->getRenderWindow();
    target->draw(this->background);
    // Desenha tiles que se encontram nos limites
    for (int layer = 0; layer < layers.size(); layer++)
        for (int tile = 0; tile < layers[layer].tiles.size(); tile++)
            if (drawingBounds.contains(layers[layer].tiles[tile].getPosition().x, layers[layer].tiles[tile].getPosition().y))
                target->draw(layers[layer].tiles[tile]);
        
}

void Mapa::reset(){
    this->background.setPosition(0, 0);
}

void Mapa::setPosition(const Vector2f& position){
    this->g_grafico->setViewPosition(position);
    this->background.setPosition(position.x - this->g_grafico->getRenderWindow()->getSize().x/2,
                                 position.y - this->g_grafico->getRenderWindow()->getSize().y/2);
}

const Vector2f& Mapa::getPosition() const {
    return this->g_grafico->getView()->getCenter();
    //return Vector2f(this->g_grafico->getView()->getCenter().x, this->g_grafico->getView()->getCenter().y);
}

// Getters & Setters
void Mapa::setTexture(Texture *texture){
    
    this->background.setTexture(texture);
}


// TileMap Methods
bool Mapa::load(){
    return this->load(this->a_tilemap, this->a_tileset);
}

using namespace std;
bool Mapa::load(const string& a_tilemap, const string& a_tileset) {
    // Update attributes
    this->a_tilemap = a_tilemap;
    this->a_tileset = a_tileset;
    
    
    TiXmlDocument levelFile(a_tilemap.c_str());
    
    if (!levelFile.LoadFile()) {
        std::cerr << "Loading level \"" << a_tilemap << "\" failed." << std::endl;
        return false;
    }

    //Map element. This is the root element for the whole file.
    TiXmlElement *map;
    map = levelFile.FirstChildElement("map");

    //Set up misc map properties.
    width = atoi(map->Attribute("width"));
    height = atoi(map->Attribute("height"));
    tileWidth = atoi(map->Attribute("tilewidth"));
    tileHeight = atoi(map->Attribute("tileheight"));

    //Tileset stuff
    TiXmlElement *tilesetElement;
    tilesetElement = map->FirstChildElement("tileset");
    this->firstTileID = atoi(tilesetElement->Attribute("firstgid"));
    spacing = 0;//atoi(tilesetElement->Attribute("spacing"));
    margin = 0;//atoi(tilesetElement->Attribute("margin"));
    
    //Tileset image
    TiXmlElement *image;
    image = tilesetElement->FirstChildElement("image");
    std::string imagepath = this->a_tileset;//"Resources/maps/tileset64.png";//tilesetElement->Attribute("source");
    
    //delete tilesetElement;
    
    if (!this->tilesetImage.loadFromFile(imagepath)){//Load the tileset image
        std::cout << "Failed to load tile sheet." << std::endl;
        return false;
    }

    this->tilesetImage.createMaskFromColor(sf::Color(255, 0, 255));

    this->tilesetTexture.loadFromImage(this->tilesetImage);
    this->tilesetTexture.setSmooth(false);

    //Columns and rows (of tileset image)
    int columns = this->tilesetTexture.getSize().x / tileWidth;
    int rows = this->tilesetTexture.getSize().y / tileHeight;

    std::vector <sf::Rect<int> > subRects;//container of subrects (to divide the tilesheet image up)

    //tiles/subrects are counted from 0, left to right, top to bottom
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < columns; x++) {
            sf::Rect <int> rect;
            rect.top = y * tileHeight;
            rect.height = /*y * tileHeight + */tileHeight;
            rect.left = x * tileWidth;
            rect.width = /*x * tileWidth +*/ tileWidth;
            subRects.push_back(rect);
        }

    //Layers
    TiXmlElement *layerElement;
    layerElement = map->FirstChildElement("layer");
    while (layerElement) {
        Layer layer;
        if (layerElement->Attribute("opacity") != NULL)//check if opacity attribute exists
            layer.opacity = 255 * strtod(layerElement->Attribute("opacity"), NULL);//convert the (string) opacity element to float;
        else
            layer.opacity = 255;//if the attribute doesnt exist, default to full opacity
        

        //Tiles
        TiXmlElement *layerDataElement;
        layerDataElement = layerElement->FirstChildElement("data");

        if (layerDataElement == NULL){
            std::cerr << "Bad map. No layer information found." << std::endl;
            return false;
        }

        TiXmlElement *tileElement;
        tileElement = layerDataElement->FirstChildElement("tile");
        
        
        if (tileElement == NULL) {
            std::cerr << "Bad map. No tile information found." << std::endl;
            return false;
        }

        int x = 0;
        int y = 0;

        while (tileElement) {
            int tileGID = 21;
            try{
                tileGID = atoi(tileElement->Attribute("gid"));
            } catch (std::exception e){
                cerr << e.what() << endl;
            }
                int subRectToUse = tileGID - this->firstTileID;//Work out the subrect ID to 'chop up' the tilesheet image.
            if (subRectToUse >= 0){//we only need to (and only can) create a sprite/tile if there is one to display
            
                sf::Sprite sprite;//sprite for the tile
                sprite.setTexture(this->tilesetTexture);
                sprite.setTextureRect(subRects[subRectToUse]);
                sprite.setPosition(x * tileWidth, y * tileHeight);

                sprite.setColor(sf::Color(255, 255, 255, layer.opacity));//Set opacity of the tile.

                //add tile to layer
                layer.tiles.push_back(sprite);
            }

            tileElement = tileElement->NextSiblingElement("tile");

            //increment x, y
            x++;
            if (x >= width){//if x has "hit" the end (right) of the map, reset it to the start (left)
                x = 0;
                y++;
                if (y >= height)
                    y = 0;
            }
        }
        //delete tileElement;
        
        layers.push_back(layer);

        layerElement = layerElement->NextSiblingElement("layer");
    }
    //delete layerElement;

    //Objects
    TiXmlElement *objectGroupElement;
    if (map->FirstChildElement("objectgroup") != NULL){//Check that there is atleast one object layer
    
        objectGroupElement = map->FirstChildElement("objectgroup");
        while (objectGroupElement){//loop through object layers
            
            TiXmlElement *objectElement;
            objectElement = objectGroupElement->FirstChildElement("object");
            while (objectElement){//loop through objects
                std::string objectType;
                if (objectElement->Attribute("type") != NULL)
                    objectType = objectElement->Attribute("type");
                
                std::string objectName;
                if (objectElement->Attribute("name") != NULL)
                    objectName = objectElement->Attribute("name");
                
                int x = atoi(objectElement->Attribute("x"));
                int y = atoi(objectElement->Attribute("y"));
                int width = atoi(objectElement->Attribute("width"));
                int height = atoi(objectElement->Attribute("height"));

                Object object;
                object.name = objectName;
                object.type = objectType;

                sf::Rect <int> objectRect;
                objectRect.top = y;
                objectRect.left = x;
                objectRect.height = y + height;
                objectRect.width = x + width;

                if (objectType == "solid")
                    solidObjects.push_back(objectRect);
                
                object.rect = objectRect;

                TiXmlElement *properties;
                properties = objectElement->FirstChildElement("properties");
                if (properties != NULL){
                    TiXmlElement *prop;
                    prop = properties->FirstChildElement("property");
                    if (prop != NULL) {
                        while(prop) {
                            std::string propertyName = prop->Attribute("name");
                            std::string propertyValue = prop->Attribute("value");

                            object.properties[propertyName] = propertyValue;

                            prop = prop->NextSiblingElement("property");
                        }
                    }
                    //delete prop;
                }

                objects.push_back(object);

                objectElement = objectElement->NextSiblingElement("object");
            }
            objectGroupElement = objectGroupElement->NextSiblingElement("objectgroup");
        }
        //delete objectGroupElement;
    } else
        std::cout << "No object layers found..." << std::endl;
    
    //delete map;
    map->Clear();
    return true;
}

Object Mapa::GetObject(std::string name)
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i].name == name)
        {
            return objects[i];
        }
    }
    return objects[0];
}

void Mapa::SetDrawingBounds(sf::Rect<float> bounds)
{
    drawingBounds = bounds;
    //Adjust the rect so that tiles are drawn just off screen, so you don't see them disappearing.
    drawingBounds.top -= tileHeight;
    drawingBounds.left -= tileWidth;
    drawingBounds.width += tileWidth;
    drawingBounds.height += tileHeight;
}




}}}
