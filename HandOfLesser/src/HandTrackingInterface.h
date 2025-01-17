#pragma once

#include <d3d11.h> // Why do you need this??
#include <openxr/openxr_platform.h>
#include <openxr/openxr.hpp>

class HandTrackingInterface
{
public:
	static void init(xr::UniqueDynamicInstance& instance);

	static void createHandTracker(xr::UniqueDynamicSession& session, XrHandEXT side, XrHandTrackerEXT& handTrackerOut);
	static void locateHandJoints(
		XrHandTrackerEXT& handTracker,
		xr::UniqueDynamicSpace& space,
		XrTime time,
		XrHandJointLocationEXT* handJointLocationsOut,
		XrHandJointVelocityEXT* handJointVelocitiesOut,
		XrHandTrackingAimStateFB* aimStateOut);
	static void destroyHandTracker();

private:
	static PFN_xrCreateHandTrackerEXT xrCreateHandTrackerEXT_;
	static PFN_xrDestroyHandTrackerEXT xrDestroyHandTrackerEXT_;
	static PFN_xrLocateHandJointsEXT xrLocateHandJointsEXT_;
	
	static void initFunctions(xr::UniqueDynamicInstance& instance);

};