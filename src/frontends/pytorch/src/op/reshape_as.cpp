// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "openvino/frontend/pytorch/node_context.hpp"
#include "openvino/opsets/opset10.hpp"
#include "utils.hpp"

namespace ov {
namespace frontend {
namespace pytorch {
namespace op {

OutputVector translate_reshape_as(NodeContext& context) {
    auto input_tensor = context.get_input(0);
    auto shape_tesnor = context.get_input(1);
    auto desired_shape = context.mark_node(std::make_shared<opset10::ShapeOf>(shape_tesnor));
    return {context.mark_node(std::make_shared<opset10::Reshape>(input_tensor, desired_shape, false))};
};

}  // namespace op
}  // namespace pytorch
}  // namespace frontend
}  // namespace ov