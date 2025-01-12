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

OutputVector translate_linear(NodeContext& context) {
    auto x = context.get_input(0);
    auto y = context.get_input(1);
    auto matmul = std::make_shared<opset10::MatMul>(x, y, false, true);
    return {context.mark_output(make_optional_bias(matmul, context, 2))};
};

}  // namespace op
}  // namespace pytorch
}  // namespace frontend
}  // namespace ov