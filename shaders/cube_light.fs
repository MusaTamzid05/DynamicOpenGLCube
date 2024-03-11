#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D texture1;
uniform vec3 lightPosition;

void main() {
    vec3 lightColor = vec3(1.0);
    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * lightColor;


    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = ambient + diffuse;



    FragColor = vec4(result, 1.0) * texture(texture1, TexCoord);
}
