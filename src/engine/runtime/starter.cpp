#include "starter.h"
#include "fmt/core.h"
#include <GL/glew.h>
#include <iostream>
#include <iterator>
#include <ostream>


namespace Engine::Runtime {
    

    void Starter::init() {
        startingPhase = true;
        std::cout << "init load" << " - " << startingPhase << " - " << finishedPhase  <<std::endl;
    }

    void Starter::startup() {
        std::cout << "startup seq" << " - " << startingPhase << " - " << finishedPhase  <<std::endl;
    }

    void Starter::postLoad() {
        finishedPhase = true;
        startingPhase = false;
        std::cout << "postload" << " - " << startingPhase << " - " << finishedPhase  <<std::endl; 
    }

    void Starter::terminate() {
        std::cout << "Terminate" << " - " << startingPhase << " - " << finishedPhase  <<std::endl;
    }




}
