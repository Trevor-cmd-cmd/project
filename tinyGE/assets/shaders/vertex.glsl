#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec2 TexCoord;

uniform vec3 cameraPos;
uniform vec3 objectPos;

uniform float zoom;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    
    
    vec3 pos = aPos - cameraPos;//+ //objectPos - cameraPos;
    
    TexCoord = aTexCoord;
    gl_Position = vec4(pos * zoom, 1.0);
    //gl_Position = projection * view * model * vec4(aPos  + cameraPos, 1.0);
}