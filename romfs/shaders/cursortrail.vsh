#version 100

attribute vec3 position;
attribute vec2 uv;

uniform float time;
uniform mat4 mvp;

varying vec2 tex_coord;
varying float vtx_alpha;

void main()
{	
	gl_Position = mvp * vec4(position, 1.0);
	
	tex_coord = uv;
	vtx_alpha = position.z;
}