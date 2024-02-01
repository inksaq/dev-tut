#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace core::graphics {

    class Camera3D {
    public:
        Camera3D();

        void setPosition(const glm::vec3& position);
        void setRotation(float yaw, float pitch);

        void move(const glm::vec3& offset);
        void rotate(float yawOffset, float pitchOffset);

        glm::mat4 getViewMatrix() const;
        glm::mat4 getProjectionMatrix() const;
        void update(float deltaTime);
        float getSpeed() const;
        void setSpeed(float newSpeed);

        // Additional methods for handling user input, etc.

    private:
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;

        float yaw;
        float pitch;
        float fov;
        float aspectRatio;
        float nearPlane;
        float farPlane;
        float speed;

        void updateCameraVectors();
    };
}
