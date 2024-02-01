#include "camera.h"

namespace core::graphics {

    Camera3D::Camera3D() 
        : position(0.0f, 0.0f, 3.0f), worldUp(0.0f, 1.0f, 0.0f), 
          yaw(-90.0f), pitch(0.0f), fov(45.0f), aspectRatio(1.0f), 
          nearPlane(0.1f), farPlane(100.0f) {
        updateCameraVectors();
    }

    void Camera3D::setPosition(const glm::vec3& position) {
        this->position = position;
    }

    void Camera3D::setRotation(float yaw, float pitch) {
        this->yaw = yaw;
        this->pitch = pitch;
        updateCameraVectors();
    }

    void Camera3D::move(const glm::vec3& offset) {
        position += offset;
    }

    void Camera3D::rotate(float yawOffset, float pitchOffset) {
        yaw += yawOffset;
        pitch += pitchOffset;
        updateCameraVectors();
    }

    glm::mat4 Camera3D::getViewMatrix() const {
        return glm::lookAt(position, position + front, up);
    }

    glm::mat4 Camera3D::getProjectionMatrix() const {
        return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }

    void Camera3D::setSpeed(float newSpeed){
        speed = newSpeed;
    }

    float Camera3D::getSpeed() const {
        return speed;
    }

    void Camera3D::updateCameraVectors() {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->front = glm::normalize(front);

        right = glm::normalize(glm::cross(front, worldUp));
        up = glm::normalize(glm::cross(right, front));
    }
    void Camera3D::update(float deltaTime) {
        // Example implementation - adjust based on how you want to process input

        // Handle horizontal movement


        // Constrain the pitch
        pitch = std::max(std::min(pitch, 89.0f), -89.0f);

        updateCameraVectors();
    }

}
