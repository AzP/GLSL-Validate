varying vec3 color;

void main()
{
    color = vec3(1.0, 1.0, 1.0);

    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
