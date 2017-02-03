#pragma once

#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "IRayTracer.h"

using namespace std;

class RayTracer : IRayTracer
{
	private:
		ImageBuffer buffer;


	public:
		RayTracer();

		~RayTracer();

		virtual bool init(int dim_x, int dim_y, string save_to_file_name);

		virtual void start_tracing();

		virtual void trace();

		virtual void load_scene(string scene_name);
};

#endif;