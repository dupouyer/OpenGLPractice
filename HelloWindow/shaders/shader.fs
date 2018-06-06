#version 330 core
out vec4 FragColor;

in vec2 texCoord;
in vec4 debugColor;

uniform vec4 _color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture,texCoord) * _color;
    // FragColor = debugColor;
} 