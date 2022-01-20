// This file is part of the AliceVision project.
// Copyright (c) 2017 AliceVision contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <aliceVision/depthMap/cuda/memory.hpp>
#include <aliceVision/depthMap/cuda/deviceCommon/DeviceCameraParams.hpp>

namespace aliceVision {
namespace depthMap {

class NormalMapping
{
public:
    NormalMapping();
    ~NormalMapping();

    void loadCameraParameters();
    void allocHostMaps( int w, int h );
    void copyDepthMap( const std::vector<float>& depthMap );

    const float* getDepthMapHst()  const; // an input
    float3*      getNormalMapHst();       // an output

public:
    DeviceCameraParams* cameraParameters_h;
    DeviceCameraParams* cameraParameters_d;

private:
    int     _allocated_floats;
    float*  _depthMapHst;
    float3* _normalMapHst;
};

void ps_computeNormalMap(
    NormalMapping* mapping,
    int width, int height,
    int wsh, float gammaC, float gammaP);

} // namespace depthMap
} // namespace aliceVision
