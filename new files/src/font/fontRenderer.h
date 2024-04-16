#ifndef FONTRENDERER_H
#define FONTRENDERER_H

#include "../shader/shaderManager.h"
#include "../shader/shader.h"
#include "font.h"

/**
 * @brief A font renderer
 * @details This class is used to render text using a font
 */
class FontRenderer {
    public:
        /**
         * @brief Construct a new Font Renderer object
         * @details This constructor will call the font constructor and initialize the render data
         * 
         * @param shader The shader to use
         * @param fontPath The path to the font file
         * @param fontSize The size of the font
         */
        FontRenderer(Shader& shader, std::string fontPath, int fontSize);

        /**
         * @brief Destroy the Font Renderer object
         * @details destroys the VAO and VBO associated with the font renderer
         */
        ~FontRenderer();

        /**
         * @brief Renders text on the screen
         * 
         * @param text The text to render
         * @param x The x position of the text
         * @param y The y position of the text
         * @param scale The scale of the text
         * @param color The color of the text
         */
        void renderText(std::string text, float x, float y, float scale, glm::vec3 color);

    private:
        /**
         * @brief The shader to use
         */
        Shader shader;

        /**
         * @brief The VAO and VBO associated with the font renderer
         */
        GLuint VAO, VBO;

        /**
         * @brief The projection matrix
         */
        glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f); // TODO: decide if this should be here or constant in engine class

        /**
         * @brief A set of character structs mapped to their ASCII character representations
         * @details This is the same map generated by the font class
         */
        std::map<char, Character> font;

        /**
         * @brief Initializes and configures the buffer and vertex attributes
         */
        void initRenderData();
};

#endif // FONTRENDERER_H
