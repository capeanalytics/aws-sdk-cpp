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

#include <aws/core/client/AWSError.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/email/SESErrors.h>

using namespace Aws::Client;
using namespace Aws::SES;
using namespace Aws::Utils;

namespace Aws
{
namespace SES
{
namespace SESErrorMapper
{

static const int INVALID_CONFIGURATION_SET_HASH = HashingUtils::HashString("InvalidConfigurationSet");
static const int INVALID_POLICY_HASH = HashingUtils::HashString("InvalidPolicy");
static const int INVALID_SNS_TOPIC_HASH = HashingUtils::HashString("InvalidSnsTopic");
static const int LIMIT_EXCEEDED_HASH = HashingUtils::HashString("LimitExceeded");
static const int MESSAGE_REJECTED_HASH = HashingUtils::HashString("MessageRejected");
static const int EVENT_DESTINATION_ALREADY_EXISTS_HASH = HashingUtils::HashString("EventDestinationAlreadyExists");
static const int MAIL_FROM_DOMAIN_NOT_VERIFIED_HASH = HashingUtils::HashString("MailFromDomainNotVerifiedException");
static const int CONFIGURATION_SET_ALREADY_EXISTS_HASH = HashingUtils::HashString("ConfigurationSetAlreadyExists");
static const int INVALID_LAMBDA_FUNCTION_HASH = HashingUtils::HashString("InvalidLambdaFunction");
static const int EVENT_DESTINATION_DOES_NOT_EXIST_HASH = HashingUtils::HashString("EventDestinationDoesNotExist");
static const int CANNOT_DELETE_HASH = HashingUtils::HashString("CannotDelete");
static const int CONFIGURATION_SET_DOES_NOT_EXIST_HASH = HashingUtils::HashString("ConfigurationSetDoesNotExist");
static const int RULE_DOES_NOT_EXIST_HASH = HashingUtils::HashString("RuleDoesNotExist");
static const int RULE_SET_DOES_NOT_EXIST_HASH = HashingUtils::HashString("RuleSetDoesNotExist");
static const int INVALID_CLOUD_WATCH_DESTINATION_HASH = HashingUtils::HashString("InvalidCloudWatchDestination");
static const int INVALID_FIREHOSE_DESTINATION_HASH = HashingUtils::HashString("InvalidFirehoseDestination");
static const int ALREADY_EXISTS_HASH = HashingUtils::HashString("AlreadyExists");
static const int INVALID_S3_CONFIGURATION_HASH = HashingUtils::HashString("InvalidS3Configuration");


AWSError<CoreErrors> GetErrorForName(const char* errorName)
{
  int hashCode = HashingUtils::HashString(errorName);

  if (hashCode == INVALID_CONFIGURATION_SET_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_CONFIGURATION_SET), false);
  }
  else if (hashCode == INVALID_POLICY_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_POLICY), false);
  }
  else if (hashCode == INVALID_SNS_TOPIC_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_SNS_TOPIC), false);
  }
  else if (hashCode == LIMIT_EXCEEDED_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::LIMIT_EXCEEDED), false);
  }
  else if (hashCode == MESSAGE_REJECTED_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::MESSAGE_REJECTED), false);
  }
  else if (hashCode == EVENT_DESTINATION_ALREADY_EXISTS_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::EVENT_DESTINATION_ALREADY_EXISTS), false);
  }
  else if (hashCode == MAIL_FROM_DOMAIN_NOT_VERIFIED_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::MAIL_FROM_DOMAIN_NOT_VERIFIED), false);
  }
  else if (hashCode == CONFIGURATION_SET_ALREADY_EXISTS_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::CONFIGURATION_SET_ALREADY_EXISTS), false);
  }
  else if (hashCode == INVALID_LAMBDA_FUNCTION_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_LAMBDA_FUNCTION), false);
  }
  else if (hashCode == EVENT_DESTINATION_DOES_NOT_EXIST_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::EVENT_DESTINATION_DOES_NOT_EXIST), false);
  }
  else if (hashCode == CANNOT_DELETE_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::CANNOT_DELETE), false);
  }
  else if (hashCode == CONFIGURATION_SET_DOES_NOT_EXIST_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::CONFIGURATION_SET_DOES_NOT_EXIST), false);
  }
  else if (hashCode == RULE_DOES_NOT_EXIST_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::RULE_DOES_NOT_EXIST), false);
  }
  else if (hashCode == RULE_SET_DOES_NOT_EXIST_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::RULE_SET_DOES_NOT_EXIST), false);
  }
  else if (hashCode == INVALID_CLOUD_WATCH_DESTINATION_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_CLOUD_WATCH_DESTINATION), false);
  }
  else if (hashCode == INVALID_FIREHOSE_DESTINATION_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_FIREHOSE_DESTINATION), false);
  }
  else if (hashCode == ALREADY_EXISTS_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::ALREADY_EXISTS), false);
  }
  else if (hashCode == INVALID_S3_CONFIGURATION_HASH)
  {
    return AWSError<CoreErrors>(static_cast<CoreErrors>(SESErrors::INVALID_S3_CONFIGURATION), false);
  }
  return AWSError<CoreErrors>(CoreErrors::UNKNOWN, false);
}

} // namespace SESErrorMapper
} // namespace SES
} // namespace Aws
