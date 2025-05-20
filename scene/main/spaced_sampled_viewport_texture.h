/**************************************************************************/
/*  spaced_sampled_viewport_texture.h                                     */
/**************************************************************************/

#pragma once
#include "scene/main/viewport.h"

class SpacedSampledViewportTexture : public ViewportTexture {
	GDCLASS(SpacedSampledViewportTexture, ViewportTexture);

	int x_offset = 0;
	int x_step = 1;
	int y_offset = 0;
	int y_step = 1;

protected:
	static void _bind_methods();

public:
	virtual int get_width() const override;
	virtual int get_height() const override;

	virtual Ref<Image> get_image() const override;

	SpacedSampledViewportTexture();
	~SpacedSampledViewportTexture();
};
