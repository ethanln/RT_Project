#include "stdafx.h"
#include "CameraView.h"

CameraView::CameraView(Camera* _camera, glm::vec3 _look_from, glm::vec3 _look_at, int _dim_x, int _dim_y, float _fov)
{
	this->camera = _camera;
	this->look_from = _look_from;
	this->look_at = _look_at;
	this->dim_x = _dim_x;
	this->dim_y = _dim_y;
	this->fov = _fov;

	this->setup_view_plane_coor();
}

CameraView::~CameraView()
{
	delete this->camera;
}

Ray CameraView::get_initial_ray(int _x, int _y, bool is_normalized, bool is_jitter)
{
	try
	{
		glm::vec3 p1 = this->look_from;
		glm::vec3 p2 = this->view_plane.at(_y).at(_x);
		glm::vec3 direction = is_jitter ? RayUtil::CAST_RAY_JITTER(p1, p2, this->pixel_radius_x, this->pixel_radius_y, is_normalized) : RayUtil::CAST_RAY(p1, p2, is_normalized);

		return Ray(direction, p1);
	}
	catch (const std::out_of_range& oor)
	{
		// Throw Scene Exception the coordinates are out of range.
		stringstream ss;
		ss << "(" << _x << "," << _y << ") out of range.";
		throw new CameraViewException(ss.str());
	}
}

void CameraView::set_cam_pos(glm::vec3 _new_pos)
{
	this->camera->position = _new_pos;
}

void CameraView::set_cam_orientation(glm::vec3 _new_orientation)
{
	this->camera->orientation = _new_orientation;
}

glm::vec3 CameraView::get_cam_pos()
{
	return this->camera->position;
}

glm::vec3 CameraView::get_cam_orientation()
{
	return this->camera->orientation;
}

glm::vec3 CameraView::get_look_from()
{
	return this->look_from;
}

glm::vec3 CameraView::get_look_at()
{
	return this->look_at;
}

int CameraView::get_dim_x()
{
	return this->dim_x;
}

int CameraView::get_dim_y()
{
	return this->dim_y;
}

float CameraView::get_fov()
{
	return this->fov;
}

glm::vec3 CameraView::get_pixel_coor(int _x, int _y)
{
	return this->view_plane.at(_y).at(_x);
}

CameraView CameraView::clone()
{
	try
	{
		Camera clone_camera = this->camera->clone();
		glm::vec3 clone_look_from = glm::vec3(this->look_from.x, this->look_from.y, this->look_from.z);
		glm::vec3 clone_look_at = glm::vec3(this->look_at.x, this->look_at.y, this->look_at.z);
		return CameraView(&clone_camera, clone_look_from, clone_look_at, this->dim_x, this->dim_y, this->fov);
	}
	catch (exception& e)
	{
		throw new CameraViewException("Could not clone CameraView instance.");
	}
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
	float z = Vec3Util::MAG(this->look_from - this->look_at);

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