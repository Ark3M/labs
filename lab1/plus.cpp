#include "plus.hpp"

bool find_plus(std::vector<int> mas){
    for(auto& i : mas){
        if(i < 0) return false;
    }
    return true;
}
