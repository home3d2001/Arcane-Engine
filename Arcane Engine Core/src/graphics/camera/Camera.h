#pragma once

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace arcane { namespace graphics {

	enum Camera_Movement {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UPWARDS,
		DOWNWARDS
	};

	// Default Camera Values
	const GLfloat YAW = -90.0f;
	const GLfloat PITCH = 0.0f;
	const GLfloat SPEED = 40.0f;
	const GLfloat SENSITIVITY = 0.10f;
	const GLfloat FOV = 100.0f;

	class Camera {
	private:
		// Camera Attributes
		glm::vec3 m_Position, m_Front, m_Up, m_Right, m_WorldUp;

		// Euler Angles
		GLfloat m_Yaw;
		GLfloat m_Pitch;

		// Camera Options
		GLfloat m_MovementSpeed;
		GLfloat m_MouseSensitivity;
		GLfloat m_FOV;
	public:
		/**
		* Constructs a camera using the position and up vectors
		* Default camera front is in vec3(0, 0, -1) direction
		*
		* @param position Optional. The initial position of the camera. Default is 0
		* @param up Optional. Represents the up position of the camera. Default is 0
		* @param yaw Optional. Initial yaw of the camera. Default is determined by the Camera class
		* @param pitch Optional. Initial pitch of the camera. Default is determined by the Camera class
		*/
		Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch);

		/**
		* Constructs a camera using floats to represent the position and up vectors of the camera
		* Default camera front is in vec3(0, 0, -1) direction
		*
		* @param xPos Starting x position of the camera
		* @param yPos Starting y position of the camera
		* @param zPos Starting z position of the camera
		* @param xUp X-Coordinate that represents the camera's up position
		* @param yUp Y-Coordinate that represents the camera's up position
		* @param zUp Z-Coordinate that represents the camera's up position
		* @param yaw Optional. Initial yaw of the camera. Default is determined by the Camera class
		* @param pitch Optional. Initial pitch of the camera. Default is determined by the Camera class
		*/
		Camera(GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat xUp, GLfloat yUp, GLfloat zUp, GLfloat yaw, GLfloat pitch);
		


		/**
		* Returns the view matrix for the camera's position, yaw, and pitch
		*
		* @return returns the view matrix for the camera
		*/
		glm::mat4 getViewMatrix();

		/**
		* Translates the position of the camera
		*
		* @param direction Enumeration type for the direction to move the camera
		* @param deltaTime Delta time since the last update
		*/
		void processKeyboard(Camera_Movement direction, GLfloat deltaTime);

		/**
		* Changes what the camera is looking at, by adding the offsets with a sensitivity setting
		* May also constrain the pitch
		*
		* @param xOffset The value that is added to the x-offset
		* @param yOffset The value that is added to the y-offset
		* @param constrainPitch Optional. Option to constrain the pitch. Default is true
		*/
		void processMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch);

		/**
		* Changes the camera's Field of View
		* Ensures that it doesn't go below 1 or above the maximum Field of View
		*
		* @param offset The value that is added to the Field of View
		*/
		void processMouseScroll(GLfloat yOffset);


		// Getters
		inline GLfloat getYaw() const { return m_Yaw; }
		inline GLfloat getPitch() const { return m_Pitch; }
		inline GLfloat getMovementSpeed() const { return m_MovementSpeed; }
		inline GLfloat getMouseSensitivity() const { return m_MouseSensitivity; }
		inline GLfloat getFOV() const { return m_FOV; }
		inline const glm::vec3& getFront() const { return m_Front; }
		inline const glm::vec3& getPosition() const { return m_Position; }
	private:
		/**
		* Updates the front, right, and up vectors for the camera
		* These vectors are reliant on the yaw and pitch of the camera
		*/
		void updateCameraVectors();
	};

} }