#pragma once

#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

#include <string>
#include "ImageBuffer.h"

using namespace std;

class IRayTracer
{
	public:

		virtual ~IRayTracer() {}

		virtual bool init(int dim_x, int dim_y, string save_to_file_name) = 0;

		virtual void start_tracing() = 0;

		virtual void trace() = 0;

		virtual void load_scene(string scene_name) = 0;
};
#endif
