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

#include <aws/elasticfilesystem/model/DescribeFileSystemsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::EFS::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

DescribeFileSystemsResult::DescribeFileSystemsResult()
{
}

DescribeFileSystemsResult::DescribeFileSystemsResult(const AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

DescribeFileSystemsResult& DescribeFileSystemsResult::operator =(const AmazonWebServiceResult<JsonValue>& result)
{
  const JsonValue& jsonValue = result.GetPayload();
  if(jsonValue.ValueExists("Marker"))
  {
    m_marker = jsonValue.GetString("Marker");

  }

  if(jsonValue.ValueExists("FileSystems"))
  {
    Array<JsonValue> fileSystemsJsonList = jsonValue.GetArray("FileSystems");
    for(unsigned fileSystemsIndex = 0; fileSystemsIndex < fileSystemsJsonList.GetLength(); ++fileSystemsIndex)
    {
      m_fileSystems.push_back(fileSystemsJsonList[fileSystemsIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("NextMarker"))
  {
    m_nextMarker = jsonValue.GetString("NextMarker");

  }



  return *this;
}
