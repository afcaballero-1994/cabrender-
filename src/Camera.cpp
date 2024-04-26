#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    glm::vec3 temFront;
    this->worldUp = up;
    temFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    temFront.y = sin(glm::radians(pitch));
    temFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);

    this->right = glm::normalize(glm::cross(front, worldUp));
    this->up = glm::normalize(glm::cross(right, front));

}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);;
}
