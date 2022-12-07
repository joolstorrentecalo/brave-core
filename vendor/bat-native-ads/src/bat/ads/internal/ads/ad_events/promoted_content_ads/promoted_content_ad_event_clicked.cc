/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/ads/ad_events/promoted_content_ads/promoted_content_ad_event_clicked.h"

#include "base/functional/bind.h"
#include "bat/ads/confirmation_type.h"
#include "bat/ads/internal/ads/ad_events/ad_events.h"
#include "bat/ads/internal/common/logging_util.h"
#include "bat/ads/promoted_content_ad_info.h"

namespace ads::promoted_content_ads {

void AdEventClicked::FireEvent(const PromotedContentAdInfo& ad) {
  BLOG(3, "Clicked promoted content ad with placement id "
              << ad.placement_id << " and creative instance id "
              << ad.creative_instance_id);

  LogAdEvent(ad, ConfirmationType::kClicked,
             base::BindOnce([](const bool success) {
               if (!success) {
                 BLOG(1, "Failed to log promoted content ad clicked event");
                 return;
               }

               BLOG(6, "Successfully logged promoted content ad clicked event");
             }));
}

}  // namespace ads::promoted_content_ads
