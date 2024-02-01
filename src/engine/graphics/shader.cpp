
#include "shader.h"
#include <iostream>


    const char* Shader::fileRead(const char* fileName){
    if (!std::filesystem::exists(fileName)) {
        std::cerr << "Error: File does not exist: " << fileName << std::endl;
        return nullptr;
    }
        std::ifstream file(fileName, std::ios::binary | std::ios::ate);
        if (file.good()) {
            std::cout << "File is okay" << std::endl;
        }
        /*
        if (file.is_open()) {
            std::cerr << "Error opening file(is_open):" << fileName << std::endl;
            return nullptr;
        }*/
        std::streamsize fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        char* buffer = new char[fileSize + 1];
        file.read(buffer, fileSize);
        buffer[fileSize] = '\0';
        file.close();
        return buffer;
    }


    void Shader::compileShader(GLuint shader, const char* shaderType){
        glCompileShader(shader);
        GLint shaderCompileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompileStatus);
        if (shaderCompileStatus != GL_TRUE) {
            GLint infoLogLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
            GLchar* infoLog = new GLchar[infoLogLength + 1];
            glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
            std::cout << shaderType << "Shader Compliation Error: " << infoLog << std::endl;
            delete[] infoLog;

        }
        std::cout << shaderType << "Shader Compiled" << std::endl;

    }

    void Shader::Active(){
        glUseProgram(ID);
    }
    void Shader::Delete(){
        glDeleteProgram(ID);
        
    }

    void Shader::U1f(const char* uName, float uValue) {
	    glUniform1f(glGetUniformLocation(ID, uName), static_cast<GLfloat>(uValue));
    }

    void Shader::U2f(const char* uName, float uValue, float uValue2) {
	    glUniform2f(glGetUniformLocation(ID, uName), static_cast<GLfloat>(uValue), static_cast<GLfloat>(uValue2));
    }

    void Shader::U3f(const char* uName, float uValue, float uValue2, float uValue3) {
	    glUniform3f(glGetUniformLocation(ID, uName), static_cast<GLfloat>(uValue), static_cast<GLfloat>(uValue2), static_cast<GLfloat>(uValue3));
    }

    void Shader::U1i(const char* uName, int uValue) {
	    glUniform1i(glGetUniformLocation(ID, uName), uValue);
    }

    void Shader::U1fv(const char* uName, int uValue, float uValue2[]) {
	    glUniform1fv(glGetUniformLocation(ID, uName), uValue, uValue2);
    }
