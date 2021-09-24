#version 330

// Input vertex attributes
in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;
in vec4 vertexColor;

in mat4 instanceTransform;

// Input uniform values
uniform mat4 mvp;
uniform mat4 matNormal;
uniform int dgrid;

// Output vertex attributes (to fragment shader)
out vec3 fragPosition;
out vec2 fragTexCoord;
out vec4 fragColor;
out vec3 fragNormal;
flat out int drawGrid;

// NOTE: Add here your custom variables
in vec4 color;

void main()
{
    // Compute MVP for current instance
    mat4 mvpi = mvp*instanceTransform;

    // Send vertex attributes to fragment shader
    fragPosition = vec3(mvpi*vec4(vertexPosition, 1.0));
    fragTexCoord = vertexTexCoord;
    fragColor = color;
    fragNormal = normalize(vec3(matNormal*vec4(vertexNormal, 1.0)));

    drawGrid = dgrid;

    // Calculate final vertex position
    gl_Position = mvpi*vec4(vertexPosition, 1.0);
}

