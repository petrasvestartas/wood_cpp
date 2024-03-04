#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Color;

uniform vec3 lightPos; // World space light position
uniform vec3 lightColor;
uniform float transparency; // Use this uniform to control transparency

void main()
{
    // Compute face normal using derivatives
    vec3 fdx = dFdx(FragPos);
    vec3 fdy = dFdy(FragPos);
    vec3 normal = normalize(cross(fdx, fdy));

    // Ambient Occlusion Approximation
    vec3 upVector = vec3(0.0, 1.0, 0.0); // Assuming Y is up
    float angleFactor = dot(normal, upVector) * 0.5 + 0.5; // Scale to 0-1
    vec3 ambientOcclusion = mix(vec3(0.2, 0.2, 0.2), vec3(0.8, 0.8, 0.8), angleFactor);

    // Compute lighting
    vec3 ambient = ambientOcclusion * lightColor;
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * Color;
    FragColor = vec4(result, 0.95); // Include transparency in the output color
}
