/**
 * VKTS - VulKan ToolS.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) since 2014 Norbert Nopper
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef VKTS_FN_TEXTURE_HPP_
#define VKTS_FN_TEXTURE_HPP_

#include <vkts/vkts.hpp>

namespace vkts
{

/**
 *
 * @ThreadSafe
 */
VKTS_APICALL ITextureSP VKTS_APIENTRY
textureCreate(IImageSP& stageImage, IBufferSP& stageBuffer,
              IDeviceMemorySP& stageDeviceMemory,
              const IInitialResourcesSP& initialResources,
              const ICommandBuffersSP& cmdBuffer, const std::string& name,
              const IImageDataSP& imageData, const VkImageCreateInfo& imageCreateInfo, const VkAccessFlags dstAccessMask,
              const VkImageLayout newLayout,
              const VkImageSubresourceRange& subresourceRange,
              const VkMemoryPropertyFlags memoryPropertyFlags,
              const VkSamplerCreateInfo& samplerCreateInfo,
              const VkImageViewCreateInfo& imageViewCreateInfo);

/**
 *
 * @ThreadSafe
 */
VKTS_APICALL ITextureSP VKTS_APIENTRY
textureCreate(const IInitialResourcesSP& initialResources,
              const ICommandBuffersSP& cmdBuffer, const std::string& name,
              const VkImageCreateInfo& imageCreateInfo, const VkAccessFlags dstAccessMask, const VkImageLayout newLayout,
              const VkImageSubresourceRange& subresourceRange,
              const VkMemoryPropertyFlags memoryPropertyFlags);

}

#endif /* VKTS_FN_TEXTURE_HPP_ */
