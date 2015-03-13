// define the version of GLSL to use
#version 330 core

// location and render order. Both defined for all vertices using a GL_ARRAY_BUFFER
layout(location = 0) in vec2 in_location;
layout(location = 1) in vec2 in_UV;

// uniforms
uniform vec2 characterLoc = vec2(0, 0);
uniform mat4 viewMat;


// data to be sent and interpolated to the fragment shader
out vec2 UV;

// entry point
void main()
{
	// gl_Position is a special vec4 that defines the location in space.

	// set the final position
	vec4 location = vec4(in_location, -100.f, 1.f);
	gl_Position = viewMat * (location - vec4(characterLoc, 0.f, 0.f));

	// send the data to the fragment shader and interpolates it so it has the correct value
	UV = in_UV;
}