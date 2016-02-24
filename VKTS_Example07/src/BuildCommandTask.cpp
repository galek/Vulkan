/**
 * VKTS Examples - Examples for Vulkan using VulKan ToolS.
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

#include "BuildCommandTask.hpp"

VkBool32 BuildCommandTask::execute()
{
	// TODO: Create secondary command buffer.
	// 		 Loop and update scene depending on object offset and step.
	//		 Do view culling.
	//		 If visible, add rendering to secondary command buffer.

	return VK_TRUE;
}

BuildCommandTask::BuildCommandTask(const vkts::IUpdateThreadContext& updateContext, const vkts::ISceneSP& scene, const uint32_t& objectOffset, const uint32_t& objectStep) :
	ITask(), updateContext(updateContext), scene(scene), objectOffset(objectOffset), objectStep(objectStep)
{
}

BuildCommandTask::~BuildCommandTask()
{
}
