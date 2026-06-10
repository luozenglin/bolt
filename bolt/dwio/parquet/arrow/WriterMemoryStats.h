/*
 * Copyright (c) ByteDance Ltd. and/or its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cstdint>

namespace bytedance::bolt::parquet::arrow {

struct WriterMemoryStats {
  int64_t encoderCurrentBytes{0};
  int64_t encoderEstimatedDataEncodedBytes{0};
  int64_t dictEncoderCurrentBytes{0};
  int64_t dictEncoderEstimatedDataEncodedBytes{0};
  int64_t bufferedPageAllocatedBytes{0};
  int64_t bufferedPageActualMemoryBytes{0};
  int64_t bufferedPageFallbackAllocatedBytes{0};
  int64_t bufferedPageWriterDataPageAllocatedBytes{0};
  int64_t bufferedPageWriterDataPageFallbackAllocatedBytes{0};
  int64_t bufferedPageWriterDataPageCount{0};
  int64_t bufferedPageWriterDictionaryPageAllocatedBytes{0};
  int64_t bufferedPageWriterDictionaryPageFallbackAllocatedBytes{0};
  int64_t bufferedPageWriterDictionaryPageCount{0};
  int64_t pageBufferArenaCapacityBytes{0};
  int64_t pageBufferArenaReservedBytes{0};
  int64_t sharedColumnScratchAllocatedBytes{0};
  int64_t columnScratchAllocatedBytes{0};
  int64_t writeContextScratchAllocatedBytes{0};
  int64_t trackedWriterMemoryBytes{0};
};

inline void AddWriterMemoryStats(
    WriterMemoryStats& destination,
    const WriterMemoryStats& source) {
  destination.encoderCurrentBytes += source.encoderCurrentBytes;
  destination.encoderEstimatedDataEncodedBytes +=
      source.encoderEstimatedDataEncodedBytes;
  destination.dictEncoderCurrentBytes += source.dictEncoderCurrentBytes;
  destination.dictEncoderEstimatedDataEncodedBytes +=
      source.dictEncoderEstimatedDataEncodedBytes;
  destination.bufferedPageAllocatedBytes += source.bufferedPageAllocatedBytes;
  destination.bufferedPageActualMemoryBytes +=
      source.bufferedPageActualMemoryBytes;
  destination.bufferedPageFallbackAllocatedBytes +=
      source.bufferedPageFallbackAllocatedBytes;
  destination.bufferedPageWriterDataPageAllocatedBytes +=
      source.bufferedPageWriterDataPageAllocatedBytes;
  destination.bufferedPageWriterDataPageFallbackAllocatedBytes +=
      source.bufferedPageWriterDataPageFallbackAllocatedBytes;
  destination.bufferedPageWriterDataPageCount +=
      source.bufferedPageWriterDataPageCount;
  destination.bufferedPageWriterDictionaryPageAllocatedBytes +=
      source.bufferedPageWriterDictionaryPageAllocatedBytes;
  destination.bufferedPageWriterDictionaryPageFallbackAllocatedBytes +=
      source.bufferedPageWriterDictionaryPageFallbackAllocatedBytes;
  destination.bufferedPageWriterDictionaryPageCount +=
      source.bufferedPageWriterDictionaryPageCount;
  destination.pageBufferArenaCapacityBytes +=
      source.pageBufferArenaCapacityBytes;
  destination.pageBufferArenaReservedBytes +=
      source.pageBufferArenaReservedBytes;
  destination.sharedColumnScratchAllocatedBytes +=
      source.sharedColumnScratchAllocatedBytes;
  destination.columnScratchAllocatedBytes += source.columnScratchAllocatedBytes;
  destination.writeContextScratchAllocatedBytes +=
      source.writeContextScratchAllocatedBytes;
  destination.trackedWriterMemoryBytes += source.trackedWriterMemoryBytes;
}

} // namespace bytedance::bolt::parquet::arrow
