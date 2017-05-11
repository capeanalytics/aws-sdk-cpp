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

#include <aws/kinesis/model/GetRecordsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Kinesis::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetRecordsResult::GetRecordsResult() : 
    m_millisBehindLatest(0)
{
}

GetRecordsResult::GetRecordsResult(const AmazonWebServiceResult<JsonValue>& result) : 
    m_millisBehindLatest(0)
{
  *this = result;
}

GetRecordsResult& GetRecordsResult::operator =(const AmazonWebServiceResult<JsonValue>& result)
{
  const JsonValue& jsonValue = result.GetPayload();
  if(jsonValue.ValueExists("Records"))
  {
    Array<JsonValue> recordsJsonList = jsonValue.GetArray("Records");
    for(unsigned recordsIndex = 0; recordsIndex < recordsJsonList.GetLength(); ++recordsIndex)
    {
      m_records.push_back(recordsJsonList[recordsIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("NextShardIterator"))
  {
    m_nextShardIterator = jsonValue.GetString("NextShardIterator");

  }

  if(jsonValue.ValueExists("MillisBehindLatest"))
  {
    m_millisBehindLatest = jsonValue.GetInt64("MillisBehindLatest");

  }



  return *this;
}
