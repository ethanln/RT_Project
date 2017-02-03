#include "stdafx.h"
#include "CameraView.h"

CameraView::CameraView(glm::vec3 _pos, glm::vec3 _orientation, glm::vec3 _look_from, glm::vec3 _look_at, float _dim_x, float _dim_y, float _fov)
{
	this->cam = new Camera(_pos, _orientation);
	this->look_from = _look_from;
	this->look_at = _look_at;
	this->dim_x = _dim_x;
	this->dim_y = _dim_y;
	this->fov = _fov;

	this->setup_view_plane_coor();
}

CameraView::~CameraView()
{
	delete this->cam;
}

glm::vec3 CameraView::cast_ray(int _x, int _y)
{
	// IMPLEMENT: is this cohesive with the class?
}

glm::vec3 CameraView::cast_jitter_ray(int _x, int _y)
{
	// IMPLEMENT: is this cohesive with the class?
}

void CameraView::set_cam_pos(glm::vec3 _new_pos)
{
	this->cam->position = _new_pos
}

void CameraView::set_cam_orientation(glm::vec3 _new_orientation)
{
	this->cam->orientation = _new_orientation;
}

glm::vec3 CameraView::get_cam_pos()
{
	return this->cam->position;
}

glm::vec3 CameraView::get_cam_orientation()
{
	return this->cam->orientation;
}

int CameraView::get_dim_x()
{
	return this->dim_x;
}

int CameraView::get_dim_y()
{
	return this->dim_y;
}

void CameraView::print_viewplane()
{
	// IMPLEMENT
}

void CameraView::setup_view_plane_coor()
{
	float z = MathUtil::MAG(this->look_from - this->look_at);

	float max_x, max_y = z / cos(this->fov / 2.0f);
	float min_x, min_y = -(z / cos(this->fov / 2.0f));

	float increment_x = (max_x * 2.0f) / this->dim_x;
	float increment_y = (max_y * 2.0f) / this->dim_y;

	float current_x = min_x;
	float current_y = max_y;

	for (unsigned int i = 0; i < this->dim_y; i++) {
		this->view_plane.push_back(vector<glm::vec3>());

		for (unsigned int j = 0; j < this->dim_x; j++)
		{
			this->view_plane.at(i).push_back(glm::vec3(current_x, current_y, 0.0f));
			current_x += increment_x;	
		}
		current_y -= increment_y;
	}
}