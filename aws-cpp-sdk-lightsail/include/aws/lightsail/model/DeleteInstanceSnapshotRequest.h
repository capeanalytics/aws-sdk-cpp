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
#include <aws/lightsail/Lightsail_EXPORTS.h>
#include <aws/lightsail/LightsailRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Lightsail
{
namespace Model
{

  /**
   */
  class AWS_LIGHTSAIL_API DeleteInstanceSnapshotRequest : public LightsailRequest
  {
  public:
    DeleteInstanceSnapshotRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline const Aws::String& GetInstanceSnapshotName() const{ return m_instanceSnapshotName; }

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline void SetInstanceSnapshotName(const Aws::String& value) { m_instanceSnapshotNameHasBeenSet = true; m_instanceSnapshotName = value; }

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline void SetInstanceSnapshotName(Aws::String&& value) { m_instanceSnapshotNameHasBeenSet = true; m_instanceSnapshotName = std::move(value); }

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline void SetInstanceSnapshotName(const char* value) { m_instanceSnapshotNameHasBeenSet = true; m_instanceSnapshotName.assign(value); }

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline DeleteInstanceSnapshotRequest& WithInstanceSnapshotName(const Aws::String& value) { SetInstanceSnapshotName(value); return *this;}

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline DeleteInstanceSnapshotRequest& WithInstanceSnapshotName(Aws::String&& value) { SetInstanceSnapshotName(std::move(value)); return *this;}

    /**
     * <p>The name of the snapshot to delete.</p>
     */
    inline DeleteInstanceSnapshotRequest& WithInstanceSnapshotName(const char* value) { SetInstanceSnapshotName(value); return *this;}

  private:
    Aws::String m_instanceSnapshotName;
    bool m_instanceSnapshotNameHasBeenSet;
  };

} // namespace Model
} // namespace Lightsail
} // namespace Aws
