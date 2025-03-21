#pragma once
#include <cmath>
#include <cfloat>

namespace dae
{
	/* --- HELPER STRUCTS --- */
	struct Int2
	{
		int x{};
		int y{};
	};

	/* --- CONSTANTS --- */
	constexpr auto PI = 3.14159265358979323846f;
	constexpr auto PI_DIV_2 = 1.57079632679489661923f;
	constexpr auto PI_DIV_4 = 0.785398163397448309616f;
	constexpr auto PI_2 = 6.283185307179586476925f;
	constexpr auto PI_4 = 12.56637061435917295385f;

	constexpr auto TO_DEGREES = (180.0f / PI);
	constexpr auto TO_RADIANS(PI / 180.0f);

	/* --- HELPER FUNCTIONS --- */
	inline float Square(float a)
	{
		return a * a;
	}

	inline float Lerpf(float a, float b, float factor)
	{
		return ((1 - factor) * a) + (factor * b);
	}

	inline bool AreEqual(float a, float b, float epsilon = FLT_EPSILON)
	{
		return abs(a - b) < epsilon;
	}

	inline int Clamp(const int v, int min, int max)
	{
		if (v < min) return min;
		if (v > max) return max;
		return v;
	}

	inline float Clamp(const float v, float min, float max)
	{
		if (v < min) return min;
		if (v > max) return max;
		return v;
	}

	inline float Saturate(const float v)
	{
		if (v < 0.f) return 0.f;
		if (v > 1.f) return 1.f;
		return v;
	}

	// Remap the value from [min, max] to [0, 1], clamping out-of-range values
	inline float Remap(const float v, const float min, const float max)	// remap the value from [min,max] to [0,1]
	{
		if (v < min) return 0;	 // Clamp below range
		// This should be done in renderer by checking the min value of all depth buffer values and using that as the input for min. 
		// BUT -> because these multiple for loops etc tank performance, I will keep it like this for now.
		if (v > max) return 1;	 // Clamp above range
		if (max - min == 0) return 0; // Avoid division by zero

		return (v - min) / (max - min);
	}
}