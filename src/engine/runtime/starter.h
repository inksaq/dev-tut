#pragma once



namespace Engine::Runtime {

class Starter {

    public:
        void init();
        void startup();
        void postLoad();
        void terminate();


    private:
        bool startingPhase;
        bool finishedPhase;





};




}
