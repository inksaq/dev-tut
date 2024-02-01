#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <filesystem>
#include <fstream>


    class Shader {
        public:
            GLuint ID = glCreateProgram();
            Shader(const char* fragPath, const char* vertPath){
                std::cout << "File Path: " << fragPath << std::endl;

                std::cout << "CWD: " << std::filesystem::current_path() << std::endl;
                const char* vertexShaderSource = fileRead(vertPath);
                const char* fragmentShaderSource = fileRead(fragPath);
                // Create Vertex Shader Object
                GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
                compileShader(vertexShader, "Vertex");

                // Create Fragment Shader Object
                GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
                compileShader(fragmentShader, "Fragment");
                std::cout << "shader compled" << std::endl;
                // Create Shader Program Object
                glAttachShader(ID, vertexShader);
                glAttachShader(ID, fragmentShader);
                glLinkProgram(ID);
std::cout << "shader att + link" << std::endl;
                
                // Delete the now useless Vertex and Fragment Shader objects
                //glDeleteShader(vertexShader);
                //glDeleteShader(fragmentShader);
              
                //delete[] vertexShaderSource;
                //delete[] fragmentShaderSource;
std::cout << "complete" << std::endl;
            }
            const char* fileRead(const char* fileName);
            void compileShader(GLuint shader, const char* shaderType);
            void Active();
            void Delete();

            void U1f(const char* uName, float uValue);
            void U2f(const char* uName, float uValue, float uValue2);
            void U3f(const char* uName, float uValue, float uValue2, float uValue3);
            void U1i(const char* uName, int uValue);
            void U1fv(const char* uName, int uValue, float uValue2[]); 

    };




