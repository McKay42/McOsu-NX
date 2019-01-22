#version 100

attribute vec3 position;
attribute vec2 uv;

varying vec2 tex_coord;

uniform mat4 mvp;

void main()
{	
	gl_Position = mvp * vec4(position, 1.0);
	tex_coord = uv;
}