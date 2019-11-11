//
//  ResourcesHolder.h
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/6/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef ResourcesHolder_h
#define ResourcesHolder_h

#include "../base_includes.hpp"

#include <SFML/Graphics.hpp>

namespace Game {

template<typename Resource, typename Id>
class ResourceHolder {
private:
    // Attribute
    map<Id, unique_ptr<Resource>> resources_map;
    // Private Methods
    void insert(Id id, unique_ptr<Resource> resource);
public:
    // Constructor & Destructor
    ResourceHolder();
    ~ResourceHolder();
    // Methods
    void load(Id id, const string& filename);
    Resource& get(Id id);
    const Resource& get(Id id) const;
    
};
template <typename Resource, typename Id>
ResourceHolder<Resource, Id>::ResourceHolder():
resources_map(){
    
}

template <typename Resource, typename Id>
ResourceHolder<Resource, Id>::~ResourceHolder(){
    
}

template <typename Resource, typename Id>
void ResourceHolder<Resource, Id>::load(Id id, const string& filename) {
    unique_ptr<Resource> resource(new Resource());
    
    if (!resource->loadFromFile(filename))
        throw runtime_error("ResourceHolder::load(): error loading " + filename);
    
    insert(id, move(resource));
}

template <typename Resource, typename Id>
Resource& ResourceHolder<Resource, Id>::get(Id id) {
    auto resource = this->resources_map.find(id); // Busca recurso no mapa
    return *resource->second;
}

template <typename Resource, typename Id>
const Resource& ResourceHolder<Resource, Id>::get(Id id) const {
    auto resource = this->mResourceMap.find(id); // Busca recurso no mapa
    return *resource->second;
}

template <typename Resource, typename Id>
void ResourceHolder<Resource, Id>::insert(Id id, std::unique_ptr<Resource> resource) {
    // Insert and check success
    if (!this->resources_map.insert(make_pair(id, move(resource))).second)
        throw runtime_error("ResourceHolder::insert(): error inserting ");
        
}

};
#endif /* ResourcesHolder_h */
