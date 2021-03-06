﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/inspector/model/AgentsFilter.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Inspector
{
namespace Model
{

AgentsFilter::AgentsFilter() : 
    m_agentHealthListHasBeenSet(false)
{
}

AgentsFilter::AgentsFilter(const JsonValue& jsonValue) : 
    m_agentHealthListHasBeenSet(false)
{
  *this = jsonValue;
}

AgentsFilter& AgentsFilter::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("agentHealthList"))
  {
    Array<JsonValue> agentHealthListJsonList = jsonValue.GetArray("agentHealthList");
    for(unsigned agentHealthListIndex = 0; agentHealthListIndex < agentHealthListJsonList.GetLength(); ++agentHealthListIndex)
    {
      m_agentHealthList.push_back(agentHealthListJsonList[agentHealthListIndex].AsString());
    }
    m_agentHealthListHasBeenSet = true;
  }

  return *this;
}

JsonValue AgentsFilter::Jsonize() const
{
  JsonValue payload;

  if(m_agentHealthListHasBeenSet)
  {
   Array<JsonValue> agentHealthListJsonList(m_agentHealthList.size());
   for(unsigned agentHealthListIndex = 0; agentHealthListIndex < agentHealthListJsonList.GetLength(); ++agentHealthListIndex)
   {
     agentHealthListJsonList[agentHealthListIndex].AsString(m_agentHealthList[agentHealthListIndex]);
   }
   payload.WithArray("agentHealthList", std::move(agentHealthListJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace Inspector
} // namespace Aws