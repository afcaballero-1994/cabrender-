#pragma once
#include <glm/glm.hpp>

enum class CAMERADIRECTION {
    FORWARD, BACKWARD,
    LEFT, RIGHT
};


struct Camera{
    const float yaw = -90.0f;
    const float pitch = 0.0f;
    const float fov = 45.0f;

    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right;
    glm::vec3 worldUp;
    Camera();
    [[nodiscard]] glm::mat4 getViewMatrix() const;
};