/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "storage/StorageHttpHandler.h"

#include <proxygen/lib/http/ProxygenErrorEnum.h>
#include <proxygen/httpserver/ResponseBuilder.h>

namespace nebula {
namespace storage {

using proxygen::HTTPMessage;
using proxygen::HTTPMethod;
using proxygen::ProxygenError;
using proxygen::UpgradeProtocol;

void StorageHttpHandler::onRequest(std::unique_ptr<HTTPMessage> headers) noexcept {
    if (headers->hasQueryParam("key") && headers->hasQueryParam("value")) {
    } else {
    }
}

void StorageHttpHandler::onBody(std::unique_ptr<folly::IOBuf>) noexcept {
}

void StorageHttpHandler::onEOM() noexcept {
}

void StorageHttpHandler::onUpgrade(proxygen::UpgradeProtocol) noexcept {
}

void StorageHttpHandler::requestComplete() noexcept {
}

void StorageHttpHandler::onError(ProxygenError error) noexcept {
    LOG(ERROR) << "Storage Handler failed : "
               << proxygen::getErrorString(error);
}

}  // namespace storage
}  // namespace nebula
