#version 330 core

layout (location=0) in vec3 position;
layout (location=1) in vec2 texCoord;
layout (location=2) in vec3 normal;


uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

void main() {
    FragPos = vec3(model * vec4(position, 1.0));
    gl_Position = projection * view * model * vec4(position, 1.0);
    TexCoord = vec2(texCoord.x, texCoord.y);

    Normal = normal;
}
