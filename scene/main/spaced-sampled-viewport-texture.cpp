/**************************************************************************/
/*  spaced-sampled-viewport-texture.cpp                                   */
/**************************************************************************/

#include "spaced_sampled_viewport_texture.h"

int SpacedSampledViewportTexture::get_width() const {
	return (ViewportTexture::get_width() - x_offset - 1) / x_step + 1
}

int SpacedSampledViewportTexture::get_height() const {
	return (ViewportTexture::get_height() - y_offset - 1) / y_step + 1
}

Size2 SpacedSampledViewportTexture::get_size() const {
	return Size2(get_width(), get_height()).ceil();
}

Ref<Image> SpacedSampledViewportTexture::get_image() const {
  Ref<Image> original = ViewportTexture::get_image();
	if (!original) {
    // On error
		return original;
	}
  Ref<Image> ans = Ref<Image>::instantiate(get_width(), get_height(), true, original->get_format());
  for (int i = 0, x = x_offset; x < original->get_width(); ++i, x += x_step) {
    for (int j = 0, y = y_offset; y < original->get_height(); ++j, y += y_step) {
      ans->blit_rect(original, Rect2i(x, y, 1, 1), Point2i(i, j));
    }
  }
	return ans;
}

void SpacedSampledViewportTexture::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_x_offset", "int"), &ViewportTexture::set_x_offset);
	ClassDB::bind_method(D_METHOD("get_x_offset"), &ViewportTexture::get_x_offset);
	ClassDB::bind_method(D_METHOD("set_x_step", "int"), &ViewportTexture::set_x_step);
	ClassDB::bind_method(D_METHOD("get_x_step"), &ViewportTexture::get_x_step);
	ClassDB::bind_method(D_METHOD("set_y_offset", "int"), &ViewportTexture::set_y_offset);
	ClassDB::bind_method(D_METHOD("get_y_offset"), &ViewportTexture::get_y_offset);
	ClassDB::bind_method(D_METHOD("set_y_step", "int"), &ViewportTexture::set_y_step);
	ClassDB::bind_method(D_METHOD("get_y_step"), &ViewportTexture::get_y_step);

  ADD_PROPERTY(PropertyInfo(Variant::INT, "x_offset"), "set_x_offset", "get_x_offset");
  ADD_PROPERTY(PropertyInfo(Variant::INT, "x_step"), "set_x_step", "get_x_step");
  ADD_PROPERTY(PropertyInfo(Variant::INT, "y_offset"), "set_y_offset", "get_y_offset");
  ADD_PROPERTY(PropertyInfo(Variant::INT, "y_step"), "set_x_step", "get_x_step");
}
