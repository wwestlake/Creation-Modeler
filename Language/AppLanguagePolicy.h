#pragma once

#include <string>

namespace creation_modeler::language
{
std::string getLanguageRuntimeSummary();
std::string getAppDomainName();
bool canRunNodeDomain(const std::string& domainName);
}

