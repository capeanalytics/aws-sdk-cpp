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

#include <aws/ec2/model/CreateKeyPairResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

CreateKeyPairResponse::CreateKeyPairResponse()
{
}

CreateKeyPairResponse::CreateKeyPairResponse(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

CreateKeyPairResponse& CreateKeyPairResponse::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (!rootNode.IsNull() && (rootNode.GetName() != "CreateKeyPairResponse"))
  {
    resultNode = rootNode.FirstChild("CreateKeyPairResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode keyFingerprintNode = resultNode.FirstChild("keyFingerprint");
    if(!keyFingerprintNode.IsNull())
    {
      m_keyFingerprint = StringUtils::Trim(keyFingerprintNode.GetText().c_str());
    }
    XmlNode keyMaterialNode = resultNode.FirstChild("keyMaterial");
    if(!keyMaterialNode.IsNull())
    {
      m_keyMaterial = StringUtils::Trim(keyMaterialNode.GetText().c_str());
    }
    XmlNode keyNameNode = resultNode.FirstChild("keyName");
    if(!keyNameNode.IsNull())
    {
      m_keyName = StringUtils::Trim(keyNameNode.GetText().c_str());
    }
  }

  if (!rootNode.IsNull()) {
    XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
    m_responseMetadata = responseMetadataNode;
    AWS_LOGSTREAM_DEBUG("Aws::EC2::Model::CreateKeyPairResponse", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );
  }
  return *this;
}
