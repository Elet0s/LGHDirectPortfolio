#pragma once
class ObjectRenderer
{
private:
	ObjectRenderer();
	~ObjectRenderer();

	ObjectRenderer(const ObjectRenderer& _Other) = delete;
	ObjectRenderer(ObjectRenderer&& _Other) noexcept = delete;
	ObjectRenderer& operator=(const ObjectRenderer& _Other) = delete;
	ObjectRenderer& operator=(ObjectRenderer&& _Other) noexcept = delete;
};