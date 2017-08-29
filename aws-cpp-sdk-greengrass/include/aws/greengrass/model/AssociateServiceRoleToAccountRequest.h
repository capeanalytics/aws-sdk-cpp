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
#include <aws/greengrass/Greengrass_EXPORTS.h>
#include <aws/greengrass/GreengrassRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Greengrass
{
namespace Model
{

  /**
   */
  class AWS_GREENGRASS_API AssociateServiceRoleToAccountRequest : public GreengrassRequest
  {
  public:
    AssociateServiceRoleToAccountRequest();
    Aws::String SerializePayload() const override;


    /**
     * Role arn you wish to associate with this account.
     */
    inline const Aws::String& GetRoleArn() const{ return m_roleArn; }

    /**
     * Role arn you wish to associate with this account.
     */
    inline void SetRoleArn(const Aws::String& value) { m_roleArnHasBeenSet = true; m_roleArn = value; }

    /**
     * Role arn you wish to associate with this account.
     */
    inline void SetRoleArn(Aws::String&& value) { m_roleArnHasBeenSet = true; m_roleArn = std::move(value); }

    /**
     * Role arn you wish to associate with this account.
     */
    inline void SetRoleArn(const char* value) { m_roleArnHasBeenSet = true; m_roleArn.assign(value); }

    /**
     * Role arn you wish to associate with this account.
     */
    inline AssociateServiceRoleToAccountRequest& WithRoleArn(const Aws::String& value) { SetRoleArn(value); return *this;}

    /**
     * Role arn you wish to associate with this account.
     */
    inline AssociateServiceRoleToAccountRequest& WithRoleArn(Aws::String&& value) { SetRoleArn(std::move(value)); return *this;}

    /**
     * Role arn you wish to associate with this account.
     */
    inline AssociateServiceRoleToAccountRequest& WithRoleArn(const char* value) { SetRoleArn(value); return *this;}

  private:

    Aws::String m_roleArn;
    bool m_roleArnHasBeenSet;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
