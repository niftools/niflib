/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#include "NIF_Blocks.h"

typedef IBlock * (*blk_factory_func)();
extern map<string, blk_factory_func> global_block_map;

//--Block Class Constructors--//

AControllable::AControllable() {
	Init();
}

AController::AController() {
	AddAttr( attr_link, "Next Controller", 0, 0xFFFFFFFF );
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frequency", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Phase", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Start Time", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Stop Time", 0, 0xFFFFFFFF );
	AddAttr( attr_nodeancestor, "Target Node", 0, 0xFFFFFFFF );
	Init();
}

//AFx::AFx() {
//	AddAttr( attr_byte, "Unknown1", 0, 0xFFFFFFFF );
//	AddAttr( attr_byte, "Unknown2", 0, 0xFFFFFFFF );
//	Init();
//}

ALight::ALight() {
	AddAttr( attr_int, "Unknown Int 1", 0, 67108866 );
	AddAttr( attr_int, "Unknown Int 2", 0, 67108866 );
	AddAttr( attr_int, "Unknown3", 167837696, 0xFFFFFFFF );
	AddAttr( attr_float, "Dimmer", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Ambient Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Diffuse Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Specular Color", 0, 0xFFFFFFFF );
	Init();
}

ANamed::ANamed() {
	Init();
}

ANode::ANode() {
	AddAttr( attr_link, "Extra Data", 0, 67240448 );
	AddAttr( attr_linkgroup, "Extra Data List", 167772416, 0xFFFFFFFF );
	AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Translation", 0, 0xFFFFFFFF );
	AddAttr( attr_matrix33, "Rotation", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Scale", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Velocity", 0, 67240448 );
	AddAttr( attr_linkgroup, "Properties", 0, 0xFFFFFFFF );
	AddAttr( attr_bbox, "Bounding Box", 0, 67240448 );
	AddAttr( attr_link, "Collision Data", 167772416, 0xFFFFFFFF );
	Init();
}


AParentNode::AParentNode() {
	AddAttr( attr_linkgroup, "Children", 0, 0xFFFFFFFF );
	AddAttr( attr_linkgroup, "Effects", 0, 0xFFFFFFFF );
	Init();
}

AParticleNode::AParticleNode() {
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Unknown2", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown3", 167772416, 0xFFFFFFFF );
	Init();
}

AParticleProperty::AParticleProperty() {
	AddAttr( attr_link, "Extra Data", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	Init();
}

AParticleSystemController::AParticleSystemController() {
	AddAttr( attr_float, "Speed", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Speed Random", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 11", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 12", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Emit Start Time", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Emit Stop Time", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Emit Rate", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Start Size", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Life Time", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Start Random", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Emitter", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short 2?", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 13?", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 1?", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2?", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short 3?", 0, 0xFFFFFFFF );
	AddAttr( attr_particlegroup, "Particles", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Unknown Link", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Particle Extra", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Unknown Link 2", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Trailer", 0, 0xFFFFFFFF );
	Init();
}

AProperty::AProperty() {
	AddAttr( attr_link, "Extra Data", 0, 67240448 );
	AddAttr( attr_linkgroup, "Extra Data List", 167772416, 0xFFFFFFFF );
	AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	Init();
}

AShape::AShape() {
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Skin Instance", 0, 0xFFFFFFFF );
	Init();
}

AvoidNode::AvoidNode() {
	Init();
}

//FxButton::FxButton() {
//	Init();
//}

//FxRadioButton::FxRadioButton() {
//	AddAttr( attr_int, "Unknown3", 0, 0xFFFFFFFF );
//	AddAttr( attr_linkgroup, "Unknown4", 0, 0xFFFFFFFF );
//	Init();
//}

//FxWidget::FxWidget() {
//	Init();
//}

NiAlphaController::NiAlphaController() {
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiAlphaProperty::NiAlphaProperty() {
	AddAttr( attr_flags, "flags", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	Init();
}

NiAmbientLight::NiAmbientLight() {
	Init();
}

NiAutoNormalParticles::NiAutoNormalParticles() {
	Init();
}

NiBillboardNode::NiBillboardNode() {
	AddAttr( attr_short, "Unknown", 167837696, 0xFFFFFFFF );
	Init();
}

//NiBoneLODController::NiBoneLODController() {
//	AddAttr( attr_int, "Unknown1", 0, 0xFFFFFFFF );
//	AddAttr( attr_int, "Unknown2", 0, 0xFFFFFFFF );
//	AddAttr( attr_int, "Unknown3", 0, 0xFFFFFFFF );
//	AddAttr( attr_linkgroup, "Node Groups", 0, 0xFFFFFFFF );
//	AddAttr( attr_int, "Num Shape Groups", 0, 0xFFFFFFFF );
//	AddAttr( attr_skinshapegroup, "Shape Groups 1", 0, 0xFFFFFFFF );
//	AddAttr( attr_linkgroup, "Shape Groups 2", 0, 0xFFFFFFFF );
//	Init();
//}

NiBSAnimationNode::NiBSAnimationNode() {
	Init();
}

NiBSPArrayController::NiBSPArrayController() {
	Init();
}

NiBSParticleNode::NiBSParticleNode() {
	Init();
}

NiCamera::NiCamera() {
	AddAttr( attr_short, "Unknown Short", 167837696, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Left", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Right", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Top", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Bottom", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Near", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Frustum Far", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 167837696, 0xFFFFFFFF );
	AddAttr( attr_float, "Viewport Left", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Viewport Right", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Viewport Top", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Viewport Bottom", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "LOD Adjust", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Unknown Link?", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 167837696, 0xFFFFFFFF );
	Init();
}

NiDirectionalLight::NiDirectionalLight() {
	Init();
}

NiDitherProperty::NiDitherProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiFlipController::NiFlipController() {
	AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Delta", 0, 0xFFFFFFFF );
	AddAttr( attr_linkgroup, "Sources", 0, 0xFFFFFFFF );
	Init();
}

NiGeomMorpherController::NiGeomMorpherController() {
	AddAttr( attr_short, "Unknown", 167837696, 0xFFFFFFFF );
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	Init();
}

NiGravity::NiGravity() {
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	Init();
}

NiKeyframeController::NiKeyframeController() {
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiLODNode::NiLODNode() {
	AddAttr( attr_int, "Unknown Int", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "LOD Center", 0, 0xFFFFFFFF );
	AddAttr( attr_lodrangegroup, "LOD Levels", 0, 0xFFFFFFFF );
	Init();
}

NiLookAtController::NiLookAtController() {
	AddAttr( attr_short, "Unknown1", 167837696, 0xFFFFFFFF );
	AddAttr( attr_link, "Look At Node", 0, 0xFFFFFFFF );
	Init();
}

NiMaterialColorController::NiMaterialColorController() {
	AddAttr( attr_short, "Unknown", 167837696, 0xFFFFFFFF );
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiMaterialProperty::NiMaterialProperty() {
	AddAttr( attr_flags, "Flags", 0, 167772416 );
	AddAttr( attr_float3, "Ambient Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Diffuse Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Specular Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float3, "Emissive Color", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Glossiness", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Alpha", 0, 0xFFFFFFFF );
	Init();
}

NiNode::NiNode() {
	Init();
}

NiParticleBomb::NiParticleBomb() {
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	Init();
}

NiParticleColorModifier::NiParticleColorModifier() {
	AddAttr( attr_link, "Color Data", 0, 0xFFFFFFFF );
	Init();
}

NiParticleGrowFade::NiParticleGrowFade() {
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	Init();
}

NiParticleMeshes::NiParticleMeshes() {
	Init();
}

NiParticleMeshModifier::NiParticleMeshModifier() {
	AddAttr( attr_linkgroup, "Particle Meshes", 0, 0xFFFFFFFF );
	Init();
}

NiParticleRotation::NiParticleRotation() {
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	Init();
}

//NiParticles::NiParticles() {
//	Init();
//}

//NiParticleSystem::NiParticleSystem() {
//	AddAttr( attr_byte, "Has Modifiers", 0, 0xFFFFFFFF );
//	AddAttr( attr_linkgroup, "Modifiers", 0, 0xFFFFFFFF );
//	Init();
//}

NiParticleSystemController::NiParticleSystemController() {
	Init();
}

NiPathController::NiPathController() {
	AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 3", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Pos Data", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Float Data", 0, 0xFFFFFFFF );
	Init();
}

NiPlanarCollider::NiPlanarCollider() {
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 11", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 12", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 13", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 14", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 15", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 16", 0, 0xFFFFFFFF );
	Init();
}

//NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() {
//	Init();
//}

//NiPSysEmitterCtlr::NiPSysEmitterCtlr() {
//	AddAttr( attr_string, "Unknown String", 0, 0xFFFFFFFF );
//	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
//	Init();
//}

//NiPSysUpdateCtlr::NiPSysUpdateCtlr() {
//	Init();
//}

NiRotatingParticles::NiRotatingParticles() {
	Init();
}

NiSequenceStreamHelper::NiSequenceStreamHelper() {
	AddAttr( attr_link, "Extra Data", 0, 67240448 );
	AddAttr( attr_linkgroup, "Extra Data List", 167772416, 0xFFFFFFFF );
	AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	Init();
}

NiShadeProperty::NiShadeProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiSourceTexture::NiSourceTexture() {
	AddAttr( attr_link, "Extra Data", 0, 67240448 );
	AddAttr( attr_linkgroup, "Extra Data List", 167772416, 0xFFFFFFFF );
	AddAttr( attr_link, "Controller", 0, 0xFFFFFFFF );
	AddAttr( attr_texsource, "Texture Source", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Unknown1", 167837696, 0xFFFFFFFF );
	AddAttr( attr_pixellayout, "Pixel Layout", 0, 0xFFFFFFFF );
	AddAttr( attr_mipmapformat, "Use Mipmaps", 0, 0xFFFFFFFF );
	AddAttr( attr_alphaformat, "Alpha Format", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	Init();
}

NiSpecularProperty::NiSpecularProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiSphericalCollider::NiSphericalCollider() {
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	Init();
}

NiStencilProperty::NiStencilProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 3", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 4", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 5", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 6", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 7", 0, 0xFFFFFFFF );
	Init();
}

NiTextureEffect::NiTextureEffect() {
	AddAttr( attr_condint, "Conditional Int", 0, 67108866 );
	AddAttr( attr_linkgroup, "Unknown Node List", 167837696, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 1", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 2", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 3", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 4", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 5", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 6", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 7", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 8", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 9", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 10", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 11", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 12", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 1", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 2", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 3", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int 4", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Source Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_byte, "Unknown Byte", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 13", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 14", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 15", 0, 0xFFFFFFFF );
	AddAttr( attr_float, "Unknown Float 16", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "PS2 L", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "PS2 K", 0, 0xFFFFFFFF );
	AddAttr( attr_short, "Unknown Short", 0, 67174412 );
	Init();
}

//NiTextureTransformController::NiTextureTransformController() {
//	AddAttr( attr_int, "Unknown1", 0, 0xFFFFFFFF );
//	AddAttr( attr_byte, "Unknown2", 0, 0xFFFFFFFF );
//	AddAttr( attr_int, "Unknown3", 0, 0xFFFFFFFF );
//	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
//	Init();
//}

NiTexturingProperty::NiTexturingProperty() {
	AddAttr( attr_flags, "Flags", 0, 167772416 );
	AddAttr( attr_applymode, "Apply Mode", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Texture Count?", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Base Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Dark Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Detail Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Gloss Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Glow Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_bumpmap, "Bump Map Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_texture, "Decal 0 Texture", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown1", 167772416, 0xFFFFFFFF );
	Init();
}

NiTriShape::NiTriShape() {
	AddAttr( attr_byte, "Unknown Byte", 167772416, 0xFFFFFFFF );
	Init();
}

NiTriStrips::NiTriStrips() {
	AddAttr( attr_byte, "Unknown", 167772416, 0xFFFFFFFF );
	Init();
}

NiUVController::NiUVController() {
	AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiVertexColorProperty::NiVertexColorProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	AddAttr( attr_vertmode, "Vertex Mode", 0, 0xFFFFFFFF );
	AddAttr( attr_lightmode, "Lighting Mode", 0, 0xFFFFFFFF );
	Init();
}

NiVisController::NiVisController() {
	AddAttr( attr_link, "Data", 0, 0xFFFFFFFF );
	Init();
}

NiWireframeProperty::NiWireframeProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	Init();
}

NiZBufferProperty::NiZBufferProperty() {
	AddAttr( attr_flags, "Flags", 0, 0xFFFFFFFF );
	AddAttr( attr_int, "Unknown Int", 67174412, 0xFFFFFFFF );
	Init();
}

RootCollisionNode::RootCollisionNode() {
	Init();
}

//--Factory Functions--//

IBlock * CreateAvoidNode() {
	return new AvoidNode;
}

//IBlock * CreateFxButton() {
//	return new FxButton;
//}
//
//IBlock * CreateFxRadioButton() {
//	return new FxRadioButton;
//}
//
//IBlock * CreateFxWidget() {
//	return new FxWidget;
//}

IBlock * CreateNiAlphaController() {
	return new NiAlphaController;
}

IBlock * CreateNiAlphaProperty() {
	return new NiAlphaProperty;
}

IBlock * CreateNiAmbientLight() {
	return new NiAmbientLight;
}

IBlock * CreateNiAutoNormalParticles() {
	return new NiAutoNormalParticles;
}

IBlock * CreateNiAutoNormalParticlesData() {
	return new NiAutoNormalParticlesData;
}

IBlock * CreateNiBillboardNode() {
	return new NiBillboardNode;
}

//IBlock * CreateNiBoneLODController() {
//	return new NiBoneLODController;
//}

IBlock * CreateNiBooleanExtraData() {
	return new NiBooleanExtraData;
}

IBlock * CreateNiBSAnimationNode() {
	return new NiBSAnimationNode;
}

IBlock * CreateNiBSPArrayController() {
	return new NiBSPArrayController;
}

IBlock * CreateNiBSParticleNode() {
	return new NiBSParticleNode;
}

IBlock * CreateNiCamera() {
	return new NiCamera;
}

IBlock * CreateNiCollisionData() {
	return new NiCollisionData;
}

IBlock * CreateNiColorData() {
	return new NiColorData;
}

IBlock * CreateNiControllerSequence() {
	return new NiControllerSequence;
}

IBlock * CreateNiDirectionalLight() {
	return new NiDirectionalLight;
}

IBlock * CreateNiDitherProperty() {
	return new NiDitherProperty;
}

IBlock * CreateNiFlipController() {
	return new NiFlipController;
}

IBlock * CreateNiFloatData() {
	return new NiFloatData;
}

IBlock * CreateNiGeomMorpherController() {
	return new NiGeomMorpherController;
}

IBlock * CreateNiGravity() {
	return new NiGravity;
}

IBlock * CreateNiIntegerExtraData() {
	return new NiIntegerExtraData;
}

IBlock * CreateNiKeyframeController() {
	return new NiKeyframeController;
}

IBlock * CreateNiKeyframeData() {
	return new NiKeyframeData;
}

IBlock * CreateNiLODNode() {
	return new NiLODNode;
}

IBlock * CreateNiLookAtController() {
	return new NiLookAtController;
}

IBlock * CreateNiMaterialColorController() {
	return new NiMaterialColorController;
}

IBlock * CreateNiMaterialProperty() {
	return new NiMaterialProperty;
}

IBlock * CreateNiMorphData() {
	return new NiMorphData;
}

IBlock * CreateNiNode() {
	return new NiNode;
}

IBlock * CreateNiPalette() {
	return new NiPalette;
}

IBlock * CreateNiParticleBomb() {
	return new NiParticleBomb;
}

IBlock * CreateNiParticleColorModifier() {
	return new NiParticleColorModifier;
}

IBlock * CreateNiParticleGrowFade() {
	return new NiParticleGrowFade;
}

IBlock * CreateNiParticleMeshes() {
	return new NiParticleMeshes;
}

IBlock * CreateNiParticleMeshesData() {
	return new NiParticleMeshesData;
}

IBlock * CreateNiParticleMeshModifier() {
	return new NiParticleMeshModifier;
}

IBlock * CreateNiParticleRotation() {
	return new NiParticleRotation;
}

//IBlock * CreateNiParticles() {
//	return new NiParticles;
//}

//IBlock * CreateNiParticlesData() {
//	return new NiParticlesData;
//}

//IBlock * CreateNiParticleSystem() {
//	return new NiParticleSystem;
//}

IBlock * CreateNiParticleSystemController() {
	return new NiParticleSystemController;
}

IBlock * CreateNiPathController() {
	return new NiPathController;
}

IBlock * CreateNiPixelData() {
	return new NiPixelData;
}

IBlock * CreateNiPlanarCollider() {
	return new NiPlanarCollider;
}

IBlock * CreateNiPosData() {
	return new NiPosData;
}

//IBlock * CreateNiPSysAgeDeathModifier() {
//	return new NiPSysAgeDeathModifier;
//}

//IBlock * CreateNiPSysData() {
//	return new NiPSysData;
//}

//IBlock * CreateNiPSysEmitterCtlr() {
//	return new NiPSysEmitterCtlr;
//}

//IBlock * CreateNiPSysEmitterCtlrData() {
//	return new NiPSysEmitterCtlrData;
//}

//IBlock * CreateNiPSysUpdateCtlr() {
//	return new NiPSysUpdateCtlr;
//}

IBlock * CreateNiRotatingParticles() {
	return new NiRotatingParticles;
}

IBlock * CreateNiRotatingParticlesData() {
	return new NiRotatingParticlesData;
}

IBlock * CreateNiSequenceStreamHelper() {
	return new NiSequenceStreamHelper;
}

IBlock * CreateNiShadeProperty() {
	return new NiShadeProperty;
}

IBlock * CreateNiSkinData() {
	return new NiSkinData;
}

IBlock * CreateNiSkinInstance() {
	return new NiSkinInstance;
}

IBlock * CreateNiSkinPartition() {
	return new NiSkinPartition;
}

IBlock * CreateNiSourceTexture() {
	return new NiSourceTexture;
}

IBlock * CreateNiSpecularProperty() {
	return new NiSpecularProperty;
}

IBlock * CreateNiSphericalCollider() {
	return new NiSphericalCollider;
}

IBlock * CreateNiStencilProperty() {
	return new NiStencilProperty;
}

IBlock * CreateNiStringExtraData() {
	return new NiStringExtraData;
}

IBlock * CreateNiTextKeyExtraData() {
	return new NiTextKeyExtraData;
}

IBlock * CreateNiTextureEffect() {
	return new NiTextureEffect;
}

//IBlock * CreateNiTextureTransformController() {
//	return new NiTextureTransformController;
//}

IBlock * CreateNiTexturingProperty() {
	return new NiTexturingProperty;
}

IBlock * CreateNiTriShape() {
	return new NiTriShape;
}

IBlock * CreateNiTriShapeData() {
	return new NiTriShapeData;
}

IBlock * CreateNiTriStrips() {
	return new NiTriStrips;
}

IBlock * CreateNiTriStripsData() {
	return new NiTriStripsData;
}

IBlock * CreateNiUVController() {
	return new NiUVController;
}

IBlock * CreateNiUVData() {
	return new NiUVData;
}

IBlock * CreateNiVertexColorProperty() {
	return new NiVertexColorProperty;
}

IBlock * CreateNiVertWeightsExtraData() {
	return new NiVertWeightsExtraData;
}

IBlock * CreateNiVisController() {
	return new NiVisController;
}

IBlock * CreateNiVisData() {
	return new NiVisData;
}

IBlock * CreateNiWireframeProperty() {
	return new NiWireframeProperty;
}

IBlock * CreateNiZBufferProperty() {
	return new NiZBufferProperty;
}

IBlock * CreateRootCollisionNode() {
	return new RootCollisionNode;
}

//This function registers the factory functions with global_block_map which is used by CreateBlock
void RegisterBlockFactories () {
	global_block_map["AvoidNode"] = CreateAvoidNode;
	//global_block_map["FxButton"] = CreateFxButton;
	//global_block_map["FxRadioButton"] = CreateFxRadioButton;
	//global_block_map["FxWidget"] = CreateFxWidget;
	global_block_map["NiAlphaController"] = CreateNiAlphaController;
	global_block_map["NiAlphaProperty"] = CreateNiAlphaProperty;
	global_block_map["NiAmbientLight"] = CreateNiAmbientLight;
	global_block_map["NiAutoNormalParticles"] = CreateNiAutoNormalParticles;
	global_block_map["NiAutoNormalParticlesData"] = CreateNiAutoNormalParticlesData;
	global_block_map["NiBillboardNode"] = CreateNiBillboardNode;
	//global_block_map["NiBoneLODController"] = CreateNiBoneLODController;
	global_block_map["NiBooleanExtraData"] = CreateNiBooleanExtraData;
	global_block_map["NiBSAnimationNode"] = CreateNiBSAnimationNode;
	global_block_map["NiBSPArrayController"] = CreateNiBSPArrayController;
	global_block_map["NiBSParticleNode"] = CreateNiBSParticleNode;
	global_block_map["NiCamera"] = CreateNiCamera;
	global_block_map["NiCollisionData"] = CreateNiCollisionData;
	global_block_map["NiColorData"] = CreateNiColorData;
	global_block_map["NiControllerSequence"] = CreateNiControllerSequence;
	global_block_map["NiDirectionalLight"] = CreateNiDirectionalLight;
	global_block_map["NiDitherProperty"] = CreateNiDitherProperty;
	global_block_map["NiFlipController"] = CreateNiFlipController;
	global_block_map["NiFloatData"] = CreateNiFloatData;
	global_block_map["NiGeomMorpherController"] = CreateNiGeomMorpherController;
	global_block_map["NiGravity"] = CreateNiGravity;
	global_block_map["NiIntegerExtraData"] = CreateNiIntegerExtraData;
	global_block_map["NiKeyframeController"] = CreateNiKeyframeController;
	global_block_map["NiKeyframeData"] = CreateNiKeyframeData;
	global_block_map["NiLODNode"] = CreateNiLODNode;
	global_block_map["NiLookAtController"] = CreateNiLookAtController;
	global_block_map["NiMaterialColorController"] = CreateNiMaterialColorController;
	global_block_map["NiMaterialProperty"] = CreateNiMaterialProperty;
	global_block_map["NiMorphData"] = CreateNiMorphData;
	global_block_map["NiNode"] = CreateNiNode;
	global_block_map["NiPalette"] = CreateNiPalette;
	global_block_map["NiParticleBomb"] = CreateNiParticleBomb;
	global_block_map["NiParticleColorModifier"] = CreateNiParticleColorModifier;
	global_block_map["NiParticleGrowFade"] = CreateNiParticleGrowFade;
	global_block_map["NiParticleMeshes"] = CreateNiParticleMeshes;
	global_block_map["NiParticleMeshesData"] = CreateNiParticleMeshesData;
	global_block_map["NiParticleMeshModifier"] = CreateNiParticleMeshModifier;
	global_block_map["NiParticleRotation"] = CreateNiParticleRotation;
	//global_block_map["NiParticles"] = CreateNiParticles;
	//global_block_map["NiParticlesData"] = CreateNiParticlesData;
	//global_block_map["NiParticleSystem"] = CreateNiParticleSystem;
	global_block_map["NiParticleSystemController"] = CreateNiParticleSystemController;
	global_block_map["NiPathController"] = CreateNiPathController;
	global_block_map["NiPixelData"] = CreateNiPixelData;
	global_block_map["NiPlanarCollider"] = CreateNiPlanarCollider;
	global_block_map["NiPosData"] = CreateNiPosData;
	//global_block_map["NiPSysAgeDeathModifier"] = CreateNiPSysAgeDeathModifier;
	//global_block_map["NiPSysData"] = CreateNiPSysData;
	//global_block_map["NiPSysEmitterCtlr"] = CreateNiPSysEmitterCtlr;
	//global_block_map["NiPSysEmitterCtlrData"] = CreateNiPSysEmitterCtlrData;
	//global_block_map["NiPSysUpdateCtlr"] = CreateNiPSysUpdateCtlr;
	global_block_map["NiRotatingParticles"] = CreateNiRotatingParticles;
	global_block_map["NiRotatingParticlesData"] = CreateNiRotatingParticlesData;
	global_block_map["NiSequenceStreamHelper"] = CreateNiSequenceStreamHelper;
	global_block_map["NiShadeProperty"] = CreateNiShadeProperty;
	global_block_map["NiSkinData"] = CreateNiSkinData;
	global_block_map["NiSkinInstance"] = CreateNiSkinInstance;
	global_block_map["NiSkinPartition"] = CreateNiSkinPartition;
	global_block_map["NiSourceTexture"] = CreateNiSourceTexture;
	global_block_map["NiSpecularProperty"] = CreateNiSpecularProperty;
	global_block_map["NiSphericalCollider"] = CreateNiSphericalCollider;
	global_block_map["NiStencilProperty"] = CreateNiStencilProperty;
	global_block_map["NiStringExtraData"] = CreateNiStringExtraData;
	global_block_map["NiTextKeyExtraData"] = CreateNiTextKeyExtraData;
	global_block_map["NiTextureEffect"] = CreateNiTextureEffect;
	//global_block_map["NiTextureTransformController"] = CreateNiTextureTransformController;
	global_block_map["NiTexturingProperty"] = CreateNiTexturingProperty;
	global_block_map["NiTriShape"] = CreateNiTriShape;
	global_block_map["NiTriShapeData"] = CreateNiTriShapeData;
	global_block_map["NiTriStrips"] = CreateNiTriStrips;
	global_block_map["NiTriStripsData"] = CreateNiTriStripsData;
	global_block_map["NiUVController"] = CreateNiUVController;
	global_block_map["NiUVData"] = CreateNiUVData;
	global_block_map["NiVertexColorProperty"] = CreateNiVertexColorProperty;
	global_block_map["NiVertWeightsExtraData"] = CreateNiVertWeightsExtraData;
	global_block_map["NiVisController"] = CreateNiVisController;
	global_block_map["NiVisData"] = CreateNiVisData;
	global_block_map["NiWireframeProperty"] = CreateNiWireframeProperty;
	global_block_map["NiZBufferProperty"] = CreateNiZBufferProperty;
	global_block_map["RootCollisionNode"] = CreateRootCollisionNode;
}
