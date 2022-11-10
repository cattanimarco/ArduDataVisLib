/*!
* \file DataSpline.h
* \author Marco Cattani <m.cattani@icloud.com>
* \version 3.0
* \date 26/02/2022
* \brief 
* \remarks None
* 
* 
* 
*/


#ifndef GRAFICI_DATA_SPLINE_INTERPOLATOR_H
#define GRAFICI_DATA_SPLINE_INTERPOLATOR_H

/*! Importation of librairies*/
#include "DataInterpolatorL.h"

/**
 * @brief Vector data source generated by interpolating the data point of a give data source
 * 
 * @tparam N 
 * @tparam AUTOSCALE 
 */
template <size_t N, bool AUTOSCALE = true>
class DataSpline : public DataInterpolatorL
{
  public:
	DataSpline(const DataSourceNorm &x, const DataSourceNorm &y)
	    : DataInterpolatorL{ x, y, N }
	{
		compute_spline();
	}

	const DataVector operator[](const unsigned long idx) const
	{
		if (idx < size())
		{
			size_t bin;
			float norm_bin_weight;

			compute_x_bin(idx, &bin, &norm_bin_weight);

			/* compute the raw range for the right bin on x */
			Range<float> raw_bin_range_x{ _x[bin].raw(), _x[bin + 1].raw() };
			float interpolated_x = raw_bin_range_x.norm_to_value(norm_bin_weight);
			/* interpolate source using spline values */
			float interpolated_y = _y[bin].raw() +
			                       _b[bin] * (interpolated_x - _x[bin].raw()) +
			                       _c[bin] * (interpolated_x - _x[bin].raw()) * (interpolated_x - _x[bin].raw()) +
			                       _d[bin] * (interpolated_x - _x[bin].raw()) * (interpolated_x - _x[bin].raw()) * (interpolated_x - _x[bin].raw());

			/* interpolate x and y by mapping the normalized bin weight over the raw bin ranges */
			/* note that we compute the norm_bin_weight on the x axis and interpolate on the y axis */
			return {
				{ interpolated_x, _x.range() },
				{ interpolated_y, _interpolated_y_range },
			};
		}
		else
		{
			return INVALID_DATA_VECTOR;
		}
	}

  private:
	void spline_data()
	{
		//assert(N >= _src_size);

		const int n = (_src_size - 1);
		float *h = static_cast<float *>(malloc(sizeof(float) * n));
		float *A = static_cast<float *>(malloc(sizeof(float) * n));
		float *l = static_cast<float *>(malloc(sizeof(float) * n + 1));
		float *u = static_cast<float *>(malloc(sizeof(float) * n + 1));
		float *z = static_cast<float *>(malloc(sizeof(float) * n + 1));

		/* compute bins' delta */
		for (int i = 0; i <= n - 1; ++i)
		{
			h[i] = _x[i + 1].raw() - _x[i].raw();
		}

		/* interpolate y */
		for (int i = 1; i <= n - 1; ++i)
		{
			A[i] = 3 * (_y[i + 1].raw() - _y[i].raw()) / h[i] - 3 * (_y[i].raw() - _y[i - 1].raw()) / h[i - 1];
		}

		l[0] = l[n] = 1;
		u[0] = z[0] = z[n] = _c[n] = 0;
		for (int i = 1; i < n; ++i)
		{
			l[i] = 2 * (_x[i + 1].raw() - _x[i - 1].raw()) - h[i - 1] * u[i - 1];
			u[i] = h[i] / l[i];
			z[i] = (A[i] - h[i - 1] * z[i - 1]) / l[i];
		}

		for (int j = n - 1; j >= 0; --j)
		{
			_c[j] = z[j] - u[j] * _c[j + 1];
			_b[j] = (_y[j + 1].raw() - _y[j].raw()) / h[j] - h[j] * (_c[j + 1] + 2 * _c[j]) / 3;
			_d[j] = (_c[j + 1] - _c[j]) / (3 * h[j]);
		}

		free(h);
		free(A);
		free(l);
		free(u);
		free(z);
	}

	void compute_spline()
	{
		// assert(N >= _src_size);

		/* compute spline parameter, than scan all x values to find new min max */
		spline_data();

		/* scan all interpolated y values to find new range */
		_interpolated_y_range = _y[0].range();

		if (AUTOSCALE)
		{
			/* use iteration over []?s */
			for (size_t idx = 0; idx < _size; ++idx)
			{
				/* update splineData min/max */
				_interpolated_y_range.update(this->y()[idx].raw());
			}
		}
	}

	float _b[N + 1];
	float _c[N + 1];
	float _d[N + 1];
	Range<float> _interpolated_y_range{ 0, 0 };
};

#endif //GRAFICI_DATA_SPLINE_INTERPOLATOR_H
