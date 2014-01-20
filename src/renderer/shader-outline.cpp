#include <llmr/renderer/shader-outline.hpp>
#include <llmr/shader/shaders.hpp>
#include <llmr/platform/gl.hpp>

using namespace llmr;

OutlineShader::OutlineShader()
    : Shader(
        shaders[OUTLINE_SHADER].vertex,
        shaders[OUTLINE_SHADER].fragment
    ) {
    if (!valid) {
        fprintf(stderr, "invalid outline shader\n");
        return;
    }

    a_pos = glGetAttribLocation(program, "a_pos");
    attributes.emplace_front(a_pos);

    u_matrix = glGetUniformLocation(program, "u_matrix");
    u_color = glGetUniformLocation(program, "u_color");
    u_world = glGetUniformLocation(program, "u_world");
}