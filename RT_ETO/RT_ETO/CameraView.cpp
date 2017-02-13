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

glm::vec3 CameraView::cast_ray(int _x, int _y, bool is_normalized, bool is_jitter)
{
	glm::vec3 p1 = this->look_from;
	glm::vec3 p2 = this->view_plane.at(_y).at(_x);
	glm::vec3 ray = is_jitter ? RayUtil::CAST_RAY_JITTER(p1, p2, this->pixel_radius_x, this->pixel_radius_y, is_normalized) : RayUtil::CAST_RAY(p1, p2, is_normalized);

	// WILL NEED TO DEFINE MORE PARAMETERS IN RAY INSTANCE AFTER DESIGNING THE CLASS MEMEBERS FOR RAY.
	return ray;
}

void CameraView::set_cam_pos(glm::vec3 _new_pos)
{
	this->cam->position = _new_pos;
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

glm::vec3 CameraView::get_pixel_coor(int _x, int _y)
{
	return this->view_plane.at(_y).at(_x);
}

void CameraView::print_viewplane(string filename)
{
	ofstream view_file;
	view_file.open(filename.c_str());
	for (unsigned int i = 0; i < this->dim_y; i++)
	{
		for (unsigned int j = 0; j < this->dim_x; j++) 
		{
			view_file << "(" << this->view_plane.at(i).at(j).x << " : " << this->view_plane.at(i).at(j).y << "),";
		}
		view_file << "\n";
	}

	view_file.close();
}

void CameraView::setup_view_plane_coor()
{
	float z = VecUtil::MAG(this->look_from - this->look_at);

	// Get the maximum x and y value of the view plane.
	float max_x = z / cos(MathUtil::TO_RADIANS(this->fov / 2.0f));
	float max_y = z / cos(MathUtil::TO_RADIANS(this->fov / 2.0f));

	// Get the minimum x and y value of the view plane.
	float min_x = -(z / cos(MathUtil::TO_RADIANS(this->fov / 2.0f)));
	float min_y = -(z / cos(MathUtil::TO_RADIANS(this->fov / 2.0f)));

	// Get the increment value for both x and y.
	float increment_x = (max_x * 2.0f) / this->dim_x;
	float increment_y = (max_y * 2.0f) / this->dim_y;

	// instantiate pixel radius.
	this->pixel_radius_x = increment_x / 2.0f;
	this->pixel_radius_y - increment_y / 2.0f;

	// instantiate the current coordinate position of the view plane 
	float current_x = min_x;
	float current_y = max_y;

	for (unsigned int i = 0; i < this->dim_y; i++) {
		this->view_plane.push_back(vector<glm::vec3>());

		for (unsigned int j = 0; j < this->dim_x; j++)
		{
			// Instantiate x,y coordinate position of the pixel index.
			this->view_plane.at(i).push_back(glm::vec3(current_x, current_y, 0.0f));

			// Increment the current x coordinate position.
			current_x += increment_x;	
		}
		// Reset current x coordinate position on the view plain.
		current_x = min_x;

		// Increment the current y coordinate position.
		current_y -= increment_y;
	}
}