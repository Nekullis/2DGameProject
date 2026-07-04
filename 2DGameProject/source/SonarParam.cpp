#include "SonarParam.h"
#include "JSONManager.h"

float SonarParam::Speed = 0.0f;
float SonarParam::MaxRadius = 0.0f;
float SonarParam::RadiusScale = 0.0f;
float SonarParam::MinLandingSpeed = 0.0f;

void SonarParam::Load()
{
    auto json = JSONManager::Read("data/json/SonarParam.json");

    Speed = json["Speed"];
    MaxRadius = json["MaxRadius"];
    RadiusScale = json["RadiusScale"];
    MinLandingSpeed = json["MinLandingSpeed"];
}
