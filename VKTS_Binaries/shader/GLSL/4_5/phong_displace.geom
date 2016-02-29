#version 450 core

// See in values in Blender file.
#define VKTS_DISPLACE_STRENGTH 1.0
#define VKTS_DISPLACE_MIDLEVEL 0.5

layout(triangles) in;

layout(triangle_strip, max_vertices = 3) out;

layout (binding = 0, std140) uniform _u_bufferViewProjection {
        mat4 projectionMatrix;
        mat4 viewMatrix;
} u_bufferViewProjection;

layout (binding = 1, std140) uniform _u_bufferTransform {
        mat4 modelMatrix;
        mat3 normalMatrix;
} u_bufferTransform;

layout (binding = 5) uniform sampler2D u_displacementTexture;

layout (location = 0) in vec3 v_g_eye[];
layout (location = 1) in vec3 v_g_normal[];
layout (location = 2) in vec3 v_g_bitangent[];
layout (location = 3) in vec3 v_g_tangent[];
layout (location = 4) in vec2 v_g_texCoord[];

layout (location = 0) out vec3 v_f_eye;
layout (location = 1) out vec3 v_f_normal;
layout (location = 2) out vec3 v_f_bitangent;
layout (location = 3) out vec3 v_f_tangent;
layout (location = 4) out vec2 v_f_texCoord;

void main(void)
{
    for(int i = 0; i < gl_in.length(); ++i)
    {
        float displace = textureLod(u_displacementTexture, v_g_texCoord[i], 0.0).r * VKTS_DISPLACE_STRENGTH - VKTS_DISPLACE_MIDLEVEL;
        
        vec4 displaceVector = vec4(0.0, displace, 0.0, 0.0);
    
        //
    
        vec4 vertex = u_bufferViewProjection.viewMatrix * u_bufferTransform.modelMatrix * (gl_in[i].gl_Position + displaceVector);
    
        v_f_eye = -vec3(vertex);
        v_f_normal = mat3(u_bufferViewProjection.viewMatrix) * u_bufferTransform.normalMatrix * v_g_normal[i];
        v_f_bitangent = mat3(u_bufferViewProjection.viewMatrix) * u_bufferTransform.normalMatrix * v_g_bitangent[i];
        v_f_tangent = mat3(u_bufferViewProjection.viewMatrix) * u_bufferTransform.normalMatrix * v_g_tangent[i];
        v_f_texCoord = v_g_texCoord[i];
    
        gl_Position = u_bufferViewProjection.projectionMatrix * vertex;

        EmitVertex();
    }
    
    EndPrimitive();
}
