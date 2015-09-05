#version 450 core

// Stage inputs
layout (location = 0) in vec3 i_vertex;
layout (location = 1) in vec3 i_color;

// Stage outputs
layout (location = 0 ) out vec3 o_color;

vec3 inv(const in vec3 v)
{
  return vec3(1.0) - v;
}

vec3 mandelbrot(const in vec2 frag, const in float zoom, const in vec2 offset)
{
  // const vec2 c = -4.0 * frag / zoom - offset;
  const vec2 c = frag;
  vec2 z = c;

  float square = 0.0;
  float x = 0.0, xt;
  float y = 0.0, yt;

  vec3 color;

  for (float i = 0.0; i < 1.0 && square < 4.0; i += 0.001)
  {
    // const float x = (z.x*z.x - z.y * z.y) + c.x
    xt = x*x - y*y - c.x;
    yt = 2.0*x*y + c.y;

    x = xt;
    y = yt;

    square = x*x + y*y;
    // color = vec3(sin(i * 2.0), i, sin(i * 2.0));
    color = inv(vec3(i, i, i));
  }
  return color;
}

// Main
void main(void)
{
  // o_color = vec3(0.0, 0.0, 1.0);
  o_color = mandelbrot(i_vertex.xy, 1.0, vec2(0.0));
}
