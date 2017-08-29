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

#pragma once
#include <aws/rekognition/Rekognition_EXPORTS.h>
#include <aws/rekognition/RekognitionRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Rekognition
{
namespace Model
{

  /**
   */
  class AWS_REKOGNITION_API GetCelebrityInfoRequest : public RekognitionRequest
  {
  public:
    GetCelebrityInfoRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline const Aws::String& GetId() const{ return m_id; }

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = std::move(value); }

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline GetCelebrityInfoRequest& WithId(const Aws::String& value) { SetId(value); return *this;}

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline GetCelebrityInfoRequest& WithId(Aws::String&& value) { SetId(std::move(value)); return *this;}

    /**
     * <p>The ID for the celebrity. You get the celebrity ID from a call to the
     * operation, which recognizes celebrities in an image. </p>
     */
    inline GetCelebrityInfoRequest& WithId(const char* value) { SetId(value); return *this;}

  private:

    Aws::String m_id;
    bool m_idHasBeenSet;
  };

} // namespace Model
} // namespace Rekognition
} // namespace Aws
